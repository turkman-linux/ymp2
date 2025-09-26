#include <core/ymp.h>
#include <core/variable.h>
#include <core/logger.h>

#include <string.h>

static int key_add(char** args){
    (void)args;
    char* name = get_value("name");
    if(strlen(name) == 0){
        print("Key name is not defined!\n");
        return 1;
    }
    return 0;
}

static int key_main(char** args){
    if(get_bool("add")){
        return key_add(args);
    }
    return 0;
}

void key_init(OperationManager *manager){
    Operation op;
    op.name = "key";
    op.alias = "k";
    op.description = "Ymp key manager";
    op.min_args = 0;
    op.call = (callback)key_main;
    operation_register(manager, op);
}