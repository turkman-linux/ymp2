#ifndef _package_h
#define _package_h
#include <utils/archive.h>

/**
 * @file package.h
 * @brief Package data
 *
 * This library store / load package information.
 */

/**
 * @struct Package
 * @brief package struct
 *
 * Store package information.
 */
typedef struct {
    char* name; /**< Package name*/
    char** dependencies; /**< Package dependencies list*/
    char* version; /**< Package version string*/
    int release; /**< Package release number*/
    bool is_source; /**< Source package status*/
    /** @cond */
    char* metadata; /** Package metadata. Used by internal functions. Do not Touch! */
    char* files; /** Package metadata. Used by internal functions. Do not Touch! */
    char* links; /** Package metadata. Used by internal functions. Do not Touch! */
    array *errors;
    Archive *archive; /** Package archive*/
    /** @endcond */
} Package;


/**
 * @brief Initializes a Package structure.
 *
 * @return A pointer to the newly created Package structure, or NULL if
 *         the initialization fails (e.g., due to memory allocation
 *         failure).
 */
Package* package_new();


void package_load_from_file(Package* pkg, const char* path);

#endif
