#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include <utils/file.h>
#include <utils/string.h>
#include <utils/yaml.h>

#include <data/package.h>
#include <data/repository.h>

visible Repository* repository_new(){
    return (Repository*)malloc(sizeof(Repository));
}

static void repository_load_data(Repository* repo, const char* data, bool is_source){
    // get area list
    int len = 0;
    char** areas;
    if(is_source) {
        areas = yaml_get_area_list(data, "source", &len);
    } else {
        areas = yaml_get_area_list(data, "package", &len);
    }
    repo->packages = realloc(repo->packages,
        (repo->package_count + (size_t)len + 1)* sizeof(Package));
    // print
    for(int i=0; i<len; i++){
        package_load_from_metadata(&(repo->packages[repo->package_count]), areas[i], is_source);
        repo->package_count++;
    }

}

visible void repository_load_from_index(Repository* repo, const char* index){
    // read index
    char* data = readfile(index);
    // get uri
    char* inner = yaml_get_area(data, "index");
    repo->uri = yaml_get_value(inner, "address");
    // load packages
    repository_load_data(repo, inner, true);
    repository_load_data(repo, inner, false);
    // cleanup
    free(data);
}