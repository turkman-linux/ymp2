#include <stdlib.h>

#include <data/repository.h>
#include <core/logger.h>
#include <core/variable.h>

#include <utils/array.h>
#include <utils/file.h>
#include <utils/string.h>

#include <config.h>

static Repository **repos;
static array *resolved;
static array *cache;
size_t depth = 0;

static void resolve_dependency_fn(char* name, bool emerge){
    if(array_has(cache, name)){
        return;
    }
    debug("Search: %s depth:%d\n", name, depth);
    for(size_t i=0; repos[i]; i++){
        Package *p = repository_get(repos[i], name, emerge);
        if(!p){
            continue;
        }
        depth++;
        for(size_t j=0; p->dependencies[j]; j++){
             resolve_dependency_fn(p->dependencies[j], emerge);
        }
        depth--;
        debug("Resolved: %s depth:%d\n", name, depth);
        array_add(resolved, name);
        i++;
    }
    array_add(cache, name);
}

static void resolve_begin(){
    resolved = array_new();
    cache = array_new();
    // search for repositories
    char* repodir = build_string("%s/%s/index", get_value("DESTDIR"), STORAGE);
    char** dirs = listdir(repodir);
    size_t i=0;
    // count repo len
    while(dirs[i]){
        i++;
    }
    repos = calloc(i+1, sizeof(Repository*));
    i=0;
    while(repos[i]){
        repos[i] = repository_new();
        repository_load_from_index(repos[i], dirs[i]);
    }
    free(dirs);
    free(repodir);
}

static void resolve_end(){
    // cleanup
    for(size_t i=0; repos[i]; i++){
        repository_unref(repos[i]);
    }
    free(repos);
    array_unref(resolved);
    array_unref(cache);
}

visible char** resolve_dependency(char* name){
    resolve_begin();
    resolve_dependency_fn(name, iseq(get_value("no-emerge"), ""));
    size_t len;
    char** ret = array_get(resolved, &len);;
    resolve_end();
    return ret;
}
