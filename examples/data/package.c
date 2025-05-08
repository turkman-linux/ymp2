#include <data/package.h>
#include <utils/error.h>
#include <stdio.h>

int main(int argc, char** argv){
    // Create a package
    Package *pkg = package_new();
    pkg->name = "foo";
    pkg->version = "1.0";
    char* deps[] = {"bar","bazz"};
    pkg->dependencies = deps;
    pkg->release = 1;
    pkg->archive = archive_new();
    
    Package* pkg2 = package_new();
    const char* path = "path/to/package.zip";
    if(argc > 1){
        path = argv[1];
    }
    package_load_from_file(pkg2, path);
    printf("%s\n", pkg2->metadata);
    error(pkg2->errors, 1);
    return 0;
}
