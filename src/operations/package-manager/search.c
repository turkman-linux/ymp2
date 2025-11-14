#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <core/ymp.h>

#include <data/repository.h>
#include <data/dependency.h>
#include <core/logger.h>

#include <utils/yaml.h>
#include <utils/string.h>

static int search_package(const char* arg, Repository **repos){
    char* arg_green = build_string(colorize_fn(colorized(GREEN, "%s"), "%s"), arg);
    for(size_t i=0; repos[i]; i++){
        for(size_t j=0; j< repos[i]->package_count;j++){
            if(strstr(repos[i]->packages[j]->name, arg) != NULL){
                const char* desc = yaml_get_value(repos[i]->packages[j]->metadata, "description");
                const char* name = repos[i]->packages[j]->name;
                char* desc_colorized = str_replace(desc, arg, arg_green);
                char* name_colorized = str_replace(name, arg, arg_green);
                printf("%s::%s: %s\n", repos[i]->name, name_colorized, desc_colorized);
                free(desc_colorized);
                free(name_colorized);
            }
        }
    }
    free(arg_green);
    return 0;
}

static int search_main(char** args){
    // Begin resolve
    Repository **repos = resolve_begin();
    if(repos == NULL){
        return 2;
    }
    int ret = 0;
    for(size_t i=0; args[i]; i++){
        if(get_bool("file")){
            //TODO: implement this
        } else {
            ret += search_package(args[i], repos);
        }
    }
    // Cleanup memory
    resolve_end(repos);
    return ret;
}

void search_init(OperationManager *manager){
    Operation op;
    op.name = "search";
    op.alias = "sr:find";
    op.description = "Search package or file";
    op.min_args = 1;
    op.call = (callback)search_main;
    op.help = help_new();
    help_add_parameter(op.help, "--file", "Search files");
    operation_register(manager, op);
}