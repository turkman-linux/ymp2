/**
 * @file string.h
 * @brief Custom string manipulation functions and macros.
 *
 * This header file provides a collection of functions for string manipulation,
 * including string comparison, length calculation, joining strings, and URL encoding/decoding.
 * It also includes macros for character classification.
 */

#ifndef _string_h
#define _string_h

#include <stddef.h>

/**
 * @brief Reads the entire content of a file into a string.
 *
 * @param path The path to the file to be read.
 * @return A pointer to the string containing the file content, or NULL if the file could not be opened or read.
 */
char* readfile(const char *path);


/**
 * @brief Compares two strings for equality.
 *
 * @param str1 The first string to compare.
 * @param str2 The second string to compare.
 * @return 1 if the strings are equal, 0 otherwise.
 */
int iseq(char* str1, char* str2);

/**
 * @brief Counts the number of tab characters in a given data string.
 *
 * @param data The string to search for tab characters.
 * @return The count of tab characters in the string.
 */
long count_tab(char* data);

/**
 * @brief Joins an array of strings into a single string with a specified delimiter.
 *
 * @param f The delimiter to use for joining.
 * @param array The array of strings to join.
 * @return A new string containing the joined strings.
 */
char* join(const char* f, char** array);

/**
 * @brief Concatenates two strings.
 *
 * @param str1 The first string.
 * @param str2 The second string.
 * @return A new string that is the concatenation of str1 and str2.
 */
char* str_add(char* str1, char* str2);

/**
 * @brief Trims whitespace from the beginning and end of a string.
 *
 * @param data The string to trim.
 * @return A new string with whitespace removed from both ends.
 */
char* trim(char* data);

/**
 * @brief Converts an integer to a string.
 *
 * @param num The integer to convert.
 * @return A string representation of the integer.
 */
char* int_to_string(int num);

/**
 * @brief Decodes a URL-encoded string.
 *
 * @param input The URL-encoded string to decode.
 * @return A new string containing the decoded result.
 */
char* url_decode(const char *input);

/**
 * @brief Encodes a string for use in a URL.
 *
 * @param input The string to encode.
 * @return A new string containing the URL-encoded result.
 */
char* url_encode(const char *input);

/**
 * @brief Checks if a string ends with a specified suffix.
 *
 * @param data The string to check.
 * @param f The suffix to check for.
 * @return 1 if data ends with f, 0 otherwise.
 */
int endswith(const char* data, const char* f);

/**
 * @brief Checks if a string starts with a specified prefix.
 *
 * @param data The string to check.
 * @param f The prefix to check for.
 * @return 1 if data starts with f, 0 otherwise.
 */
int startswith(const char* data, const char* f);

/**
 * @brief Builds a formatted string using variable arguments.
 *
 * @param format The format string.
 * @param ... The values to format into the string.
 * @return A new formatted string.
 */
char* build_string(char* format, ...);

// Macros

/** @cond */
#define isalnum_c(A) \
    (A >= 'A' && A <= 'Z') || \
    (A >= 'a' && A <= 'z') || \
    (A >= '0' && A <= '9') || \
    A == '-' || A == '_' || A == '.' || A == '~'

#define isHexDigit(A) \
    (A >= '0' && A <= '9') || \
    (A >= 'A' && A <= 'F') || \
    (A >= 'a' && A <= 'f')

/** @endcond */
#endif // _string_h

