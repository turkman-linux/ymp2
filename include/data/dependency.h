/**
 * @brief Resolves the dependencies for a given package name.
 *
 * This function takes the name of a package and returns an array of strings
 * representing the names of the dependencies required by that package.
 * The caller is responsible for freeing the returned array and its contents.
 *
 * @param name The name of the package for which to resolve dependencies.
 * @return A pointer to an array of strings containing the dependency names,
 *         or NULL if the package is not found or an error occurs.
 */
char** resolve_dependency(char* name);

