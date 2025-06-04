#include <stdio.h>

#include <core/ymp.h>
#include <core/variable.h>

#include <data/repository.h>
#include <data/dependency.h>

#include <config.h>

#include <utils/yaml.h>
#include <utils/string.h>
#include <utils/file.h>

static int install_main(char** args){
    char** res = resolve_dependency(args[0]);
    for(size_t i=0; res[i];i++){
        printf(res[i]);
    }
    return 0;
}

void install_init(OperationManager* manager){
    Operation op;
    op.name = "install";
    op.call = (callback)install_main;
    operation_register(manager, op);
}
