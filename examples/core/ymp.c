#include <stdio.h>
#include <core/ymp.h>

int main(int argc, char** argv){
    (void) argc; (void)argv;
    Ymp* ymp = ymp_init(); // Create ymp context
    printf("List all operations:\n");
    for(size_t i=0; i< ymp->manager->length;i++){
        char* name = ymp->manager->operations[i].name; // Fetch operation name from manager
        printf("  Operation: %s\n", name); // Print operation name
    }
    char* args[] = {"Hello World\n", NULL};
    int rc = operation_main(ymp->manager, "print", args); // Run an operation
    char* arg1[] = {"Hello", NULL};
    char* arg2[] = {"World", NULL};
    ymp_add(ymp, "print", arg1);
    ymp_add(ymp, "print", arg2);
    rc = ymp_run(ymp);
    return rc;
}
