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

/**
 * @brief Loads a package from a specified file.
 *
 * This function reads the contents of the file located at the given path
 * and initializes the provided Package structure with the data from the file.
 * It is expected that the file is in a specific format that the function can parse.
 *
 * @param pkg A pointer to a Package structure that will be populated with
 *            the data loaded from the file. This structure must be allocated
 *            before calling this function.
 * @param path A pointer to a null-terminated string that specifies the path
 *             to the file from which the package will be loaded. The function
 *             will attempt to open this file for reading.
 *
 * @note Ensure that the Package structure is properly initialized before
 *       calling this function. The caller is responsible for managing the
 *       memory of the Package structure.
 *
 * @warning This function may modify the contents of the Package structure
 *          if loading is successful. Ensure that the structure is in a valid
 *          state before calling this function.
 */
void package_load_from_file(Package* pkg, const char* path);


bool package_extract(Package* pkg);
#endif
