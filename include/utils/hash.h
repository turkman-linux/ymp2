#ifndef _hash_h
#define _hash_h
/**
 * @file hash.h
 * @brief Calculates the SHA-1 hash of a file.
 *
 * This function reads the contents of the file located at the specified path
 * and computes its SHA-1 hash.
 *
 * @param path A pointer to a null-terminated string that specifies the path
 *             to the file for which the SHA-1 hash will be calculated.
 *
 * @return A pointer to a string containing the SHA-1 hash in hexadecimal format,
 *         or NULL if the calculation fails (e.g., due to file access issues or
 *         memory allocation failure). The caller is responsible for freeing the
 *         returned string.
 */
char *calculate_sha1(const char *path);

/**
 * @brief Calculates the MD5 hash of a file.
 *
 * This function reads the contents of the file located at the specified path
 * and computes its MD5 hash.
 *
 * @param path A pointer to a null-terminated string that specifies the path
 *             to the file for which the MD5 hash will be calculated.
 *
 * @return A pointer to a string containing the MD5 hash in hexadecimal format,
 *         or NULL if the calculation fails (e.g., due to file access issues or
 *         memory allocation failure). The caller is responsible for freeing the
 *         returned string.
 */
char *calculate_md5(const char *path);

/**
 * @brief Calculates the SHA-256 hash of a file.
 *
 * This function reads the contents of the file located at the specified path
 * and computes its SHA-256 hash.
 *
 * @param path A pointer to a null-terminated string that specifies the path
 *             to the file for which the SHA-256 hash will be calculated.
 *
 * @return A pointer to a string containing the SHA-256 hash in hexadecimal format,
 *         or NULL if the calculation fails (e.g., due to file access issues or
 *         memory allocation failure). The caller is responsible for freeing the
 *         returned string.
 */
char *calculate_sha256(const char *path);

/**
 * @brief Calculates the SHA-512 hash of a file.
 *
 * This function reads the contents of the file located at the specified path
 * and computes its SHA-512 hash.
 *
 * @param path A pointer to a null-terminated string that specifies the path
 *             to the file for which the SHA-512 hash will be calculated.
 *
 * @return A pointer to a string containing the SHA-512 hash in hexadecimal format,
 *         or NULL if the calculation fails (e.g., due to file access issues or
 *         memory allocation failure). The caller is responsible for freeing the
 *         returned string.
 */
char *calculate_sha512(const char *path);

#endif