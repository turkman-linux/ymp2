#ifndef _logger_h
#define _logger_h
#include <stdbool.h>

/**
 * @file logger.h
 * @brief Logger module for printing messages with different severity levels.
 *
 * This module provides a simple logging mechanism with different levels of
 * severity: PRINT, DEBUG, WARNING, and INFO. It allows for easy logging
 * of messages with varying importance.
 */

/** @def PRINT
 *  @brief Log level for general print messages.
 */
#define PRINT 0

/** @def DEBUG
 *  @brief Log level for debug messages.
 */
#define DEBUG 1

/** @def WARNING
 *  @brief Log level for warning messages.
 */
#define WARNING 2

/** @def INFO
 *  @brief Log level for informational messages.
 */
#define INFO 3

/** @def ERROR
 *  @brief Log level for error messages.
 */
#define ERROR 4

#define COLORIZE 4

/**
 * @brief Set the logging status for a specific log type.
 *
 * This function allows enabling or disabling logging for a specific
 * log type (e.g., DEBUG, WARNING, etc.).
 *
 * @param type The log type to set the status for. This should be one of
 *             the defined log levels (PRINT, DEBUG, WARNING, INFO).
 * @param status A boolean value indicating whether to enable (true) or
 *               disable (false) logging for the specified type.
 */
void logger_set_status(int type, bool status);

/**
 * @brief Print a formatted message to the log.
 *
 * This function prints a formatted message to the log based on the
 * specified log type. It supports variable arguments similar to printf.
 *
 * @param caller string. It can be __func__.
 * @param type The log type for the message. This should be one of the
 *             defined log levels (PRINT, DEBUG, WARNING, INFO).
 * @param format The format string for the message, similar to printf.
 * @param ... Additional arguments for the format string.
 * @return An integer indicating the success or failure of the print operation.
 */
int print_fn(const char* caller, int type, const char* format, ...);

/**
 * @brief Macro for printing general messages.
 *
 * This macro simplifies the logging of general print messages.
 *
 * @param A The format string for the message.
 * @param ... Additional arguments for the format string.
 */
#define print(A, ...) print_fn(__func__, PRINT, A, ##__VA_ARGS__)

#ifndef NDEBUG
/**
 * @brief Macro for printing debug messages.
 *
 * This macro simplifies the logging of debug messages.
 *
 * @param A The format string for the message.
 * @param ... Additional arguments for the format string.
 */
#define debug(A, ...)   print_fn(__func__, DEBUG, A, ##__VA_ARGS__)
#else
#define debug(A, ...)
#endif

/**
 * @brief Macro for printing informational messages.
 *
 * This macro simplifies the logging of informational messages.
 *
 * @param A The format string for the message.
 * @param ... Additional arguments for the format string.
 */
#define info(A, ...)    print_fn(__func__, INFO, A, ##__VA_ARGS__)

/**
 * @brief Macro for printing warning messages.
 *
 * This macro simplifies the logging of warning messages.
 *
 * @param A The format string for the message.
 * @param ... Additional arguments for the format string.
 */
#define warning(A, ...) print_fn(__func__, WARNING, A, ##__VA_ARGS__)

#define BLACK 30
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34
#define MAGENTA 35
#define CYAN 36
#define WHITE 37

/**
 * @typedef Colorize
 * @brief Function pointer type for colorizing text.
 *
 * This typedef defines a function pointer type named Colorize that points
 * to a function taking two const char pointers as arguments and returning a
 * pointer to a char (interpreted as a colorized string).
 *
 * @param colorized A string that represents the formatted colorized text,
 *                  containing ANSI escape codes.
 * @param flat A string that represents the plain, non-colorized text.
 * @return A char pointer to the colorized string ready for output.
 */
typedef char* (*Colorize)(const char* colorized, const char* flat);

/**
 * @var colorize_fn
 * @brief Global function pointer for colorizing text.
 *
 * This variable holds the address of a function that implements the
 * colorizing behavior. It is created and used by Ymp.
 */
extern Colorize colorize_fn;

#define clr(A) #A
/**
 * @brief Constructs a colorized string with ANSI escape codes.
 *
 * This macro constructs a string that combines ANSI escape codes for text color
 * with the specified string. It is primarily used in conjunction with the
 * colorize function.
 *
 * @param color The color code (e.g., 31 for red).
 * @param message The string to be colorized.
 * @return A string literal containing the full ANSI color sequence.
 */
#define colorized(color, message) "\033[" clr(color) "m" message "\033[;0m"

/**
 * @brief Colorizes a message with the specified color.
 *
 * This function takes a color code and a message string as input, and returns
 * a new string that contains the message formatted with the specified color.
 * The color codes are based on ANSI escape codes for terminal text coloring.
 *
 * @param color The color code to apply to the message. Valid values are:
 *              - BLACK (30)
 *              - RED (31)
 *              - GREEN (32)
 *              - YELLOW (33)
 *              - BLUE (34)
 *              - MAGENTA (35)
 *              - CYAN (36)
 *              - WHITE (37)
 * @param message The message string to be colorized.
 * @return colorized message
 *
 * Example:
 * @code
 * #include <stdio.h>
 * #include <core/logger.h>
 * #include <core/ymp.h>
 *
 * int main() {
 *     ymp_init();
 *     // print messages
 *     printf("%s\n", colorize(RED,"Red Message"));
 *     printf(colorize_fn(colorized(RED,"%s")" %s\n", "%s %s\n"), "Green", "Message");
 *     // disable colorize
 *     logger_set_status(COLORIZE, false);
 *     // print messages
 *     printf("%s\n", colorize(YELLOW,"non-colorized message"));
 *     printf("%s\n", colorized("force blue message"));
 *
 *     return 0;
 * }
 * @endcode
 */
#define colorize(color, message) colorize_fn(colorized(color, message), message)



#endif
