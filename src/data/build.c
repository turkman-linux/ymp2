#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <core/ymp.h>
#include <core/logger.h>

#include <utils/string.h>
#include <utils/file.h>
#include <utils/hash.h>

#include <data/build.h>
#include <config.h>

visible char* ympbuild_get_value(ympbuild* ymp, const char* name) {
    char* command = build_string(
    "exec <&-\n"
    "{\n%s\n} &>/dev/null\n"
    "echo ${%s}", ymp->ctx, name);
    char* args[] = {"/bin/bash", "-c", command, NULL};
    char* output = strip(getoutput(args));
    debug("variable: %s -> %s\n", name, output);
    free(command);
    return output;
}

visible char** ympbuild_get_array(ympbuild* ymp, const char* name){
    char* command = build_string(
    "exec <&-\n"
    "{\n%s\n} &>/dev/null\n"
    "echo ${%s[@]}", ymp->ctx, name);
    char* args[] = {"/bin/bash", "-c", command, NULL};
    char* output = strip(getoutput(args));
    debug("variable: %s -> %s\n", name, output);
    free(command);
    return split(output," ");

}

visible int ympbuild_run_function(ympbuild* ymp, const char* name) {
    char* command = build_string(
        "exec <&-\n"
        "set +e ; %s\n"
        "%s\n"
        "set -e \n"
        "if declare -F %s ; then\n"
        "    %s\n"
        "fi", ymp->header, ymp->ctx, name);
    char* args[] = {"/bin/bash", "-c", command, NULL};
    pid_t pid = fork();
    if(pid == 0){
        execvp(args[0], args);
        free(command);
        return -1;
    } else {
        int status = 0;
        (void)waitpid(pid, &status, 0);
        free(command);
        return status;
    }
}

visible bool build_from_path(const char* path){
    char* ympfile = build_string("%s/ympbuild",path);
    if(!isfile(ympfile)){
        free(ympfile);
        return false;
    }
    // configure header
    ympbuild *ymp = malloc(sizeof(ympbuild));
    ymp->ctx = readfile(ympfile);
    ymp->header = readfile(":/ympbuild-header.sh");
    // Create build path
    ymp->path = calculate_md5(ympfile);
    ymp->path = build_string("%s/%s", BUILD_DIR, ymp->path);
    ymp->header = str_replace(ymp->header, "@buildpath@", ymp->path);
    create_dir(ymp->path);
    // fetch values
    char* name = ympbuild_get_value(ymp, "name");
    char** deps = ympbuild_get_array(ymp, "depends");
    char** sources = ympbuild_get_array(ymp, "source");
    // detect hash
    char** hashs = NULL;
    char* hash_types[] = {"sha512sums", "sha256sums", "sha1sums", "md5sums", NULL};
    for(size_t i=0; hash_types[i]; i++){
        hashs = ympbuild_get_array(ymp, hash_types[i]);
        if(strlen(hashs[0]) > 0){
            break;
        }
        if(i > 1){
            warning("Weak hash algorithm (%s) detected!.\n", hash_types[i]);
        }
        free(hashs);
    }
    for(size_t i=0; sources[i] && hashs[i]; i++){
        debug("Source: %s %s\n", sources[i], hashs[i]);
    }
    (void)name; (void)deps;
    // Cleanup
    free(ympfile);
    return true;
}
