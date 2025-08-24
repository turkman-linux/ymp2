#include <stdio.h>
#include <stdlib.h>

#include <core/ymp.h>
#include <core/operations.h>
#include <core/logger.h>

extern Ymp* global;

static int help_main(void* args){
    (void)args;
    OperationManager *manager = global->manager;
    for(size_t i=0; i < manager->length; i++){
        Operation op = manager->operations[i];
        char* name = colorize(GREEN, op.name);
        printf("%s  :  %s\n",  name, op.description);
        free(name);
    }
    return 0;
}

void help_init(OperationManager* manager){
    Operation op;
    op.name = "help";
    op.description = "Print help message";
    op.alias = "h";
    op.min_args = 0;
    op.call = (callback)help_main;
    operation_register(manager, op);
}