#include <core/ymp.h>
#include <data/build.h>

#include <stdio.h>
static int build(void** args) {
    bool status = true;
    for(size_t i=0; args[i]; i++){
        status = build_from_path(args[i]);
        if(!status){
            return 1;
        }
    }
    return 0;
}

void build_init(OperationManager* manager){
    Operation op;
    op.name = "build";
    op.call = (callback)build;
    operation_register(manager, op);
}

