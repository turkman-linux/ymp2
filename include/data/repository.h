#ifndef _repository_h
#define _repository_h
#include <data/package.h>

typedef struct {
    char* uri;
    Package* packages;
    size_t package_count;
} Repository;


Repository* repository_new();
void repository_load_from_index(Repository* repo, const char* path);
#endif
