#include <stdio.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>

visible uint64_t filesize(const char* path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        return st.st_size;
    }
    return 0; // Return 0 if the file does not exist or an error occurs
}

visible bool issymlink(const char *filename) {
    if (filename == NULL) {
        return false;
    }
    struct stat st;
    return (lstat(filename, &st) == 0) && S_ISLNK(st.st_mode);
}

visible bool isexists(const char* path) {
    struct stat path_stat;
    return (stat(path, &path_stat) == 0);
}

visible bool isdir(const char *path) {
    if (path == NULL || issymlink(path)) {
        return false;
    }
    DIR* dir = opendir(path);
    if (dir) {
        closedir(dir);
        return true;
    }
    return false;
}

visible void create_dir(const char *dir) {
    char tmp[PATH_MAX];
    char *p = NULL;
    size_t len;

    snprintf(tmp, sizeof(tmp), "%s", dir);
    len = strlen(tmp);
    
    // Remove trailing slash if present
    if (len > 0 && tmp[len - 1] == '/') {
        tmp[len - 1] = '\0';
    }

    // Create directories in the path
    for (p = tmp + 1; *p; p++) {
        if (*p == '/') {
            *p = '\0'; // Temporarily terminate the string
            mkdir(tmp, 0755); // Create the directory
            *p = '/'; // Restore the string
        }
    }
    mkdir(tmp, 0755); // Create the final directory
}

