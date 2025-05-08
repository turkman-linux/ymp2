#include <stdlib.h>

#include <data/package.h>

visible Package* package_new(){
    Package *pkg = malloc(sizeof(Package));
    return pkg;
}
