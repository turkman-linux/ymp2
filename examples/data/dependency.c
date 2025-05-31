#include <stdlib.h>
#include <stdio.h>

#include <data/dependency.h>
#include <core/logger.h>
#include <core/ymp.h>

int main(int argc, char* argv[]) {
    (void)ymp_init();
    char* pkg = "mesa";
    if(argc > 1){
        pkg = argv[1];
    }
    char** resolved = resolve_dependency(pkg);
    for(size_t i=0; resolved[i]; i++){
        printf("%s ", resolved[i]);
    }
    puts("");
    return 0;
}

