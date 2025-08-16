#include <stdio.h>

#include <core/ymp.h>
#include <core/logger.h>
#include <core/variable.h>

#include <data/repository.h>
#include <data/dependency.h>
#include <data/quarantine.h>

#include <config.h>

static int remove_main(void* args){
    char** res = (char**)args;
    Package **pkgs = resolve_reverse_dependency(res[0]);
    for(size_t j=0; pkgs[j]; j++){
        print("%s\n", pkgs[j]->name);
    }
    return 0;
}

void remove_init(OperationManager* manager){
    Operation op;
    op.name = "remove";
    op.call = (callback)remove_main;
    operation_register(manager, op);
}
