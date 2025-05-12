#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

#include <core/logger.h>

typedef int (*logger)(const char*, ...);

static logger print_functions[] = {(logger)vprintf, NULL, (logger)vprintf, NULL};

visible void logger_set_status(int type, bool status){
    if(type > (int)(sizeof(print_functions) / sizeof(logger))){
        return;
    }
    if(status){
        print_functions[type] = (logger)vprintf;
    } else {
        print_functions[type] = NULL;
    }
}

visible int print_fn(const char* caller, int type, const char* format, ...){
    if(print_functions[type] == NULL){
        return 0;
    }

    va_list args;
    va_start(args, format);
    if(type == DEBUG){
        printf("[%s]:", caller);
    }

    int status = print_functions[type](format, args);

    va_end(args);
    return status;
}
