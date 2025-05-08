#include <data/package.h>

int main(){
    // Create a package
    Package *pkg = package_new();
    pkg->name = "foo";
    pkg->version = "1.0";
    char* deps[] = {"bar","bazz"};
    pkg->dependencies = deps;
    pkg->release = 1;
    pkg->archive = archive_new();
    return 0;
}