#ifndef GPG_H
#define GPG_H

#include <stdbool.h>


/**
 * @brief Sets the GPG recipient identifier.
 *
 * This function assigns the provided recipient identifier to the global
 * variable `gpg_repicent`. This identifier will be used in GPG operations
 * such as signing and encrypting files.
 *
 * @param repicent A pointer to a string containing the recipient identifier.
 *                 This should be a valid identifier recognized by GPG.
 *
 * @note The caller is responsible for ensuring that the memory for the
 *       recipient identifier remains valid for the duration of its use.
 */
void set_gpg_repicent(char* repicent);

/**
 * @brief Signs a file using GPG.
 *
 * This function checks if the specified file exists and then signs it
 * using GPG with the recipient specified in the configuration.
 *
 * @param path The path to the file to be signed.
 * @return true if the file was successfully signed, false otherwise.
 */
bool gpg_sign_file(const char *path);

/**
 * @brief Exports a GPG public key to a file.
 *
 * This function checks if the specified file exists and then exports
 * the public key of the recipient specified in the configuration to
 * the given path.
 *
 * @param path The path where the public key will be exported.
 * @return true if the key was successfully exported, false otherwise.
 */
bool gpg_export_file(const char *path);

/**
 * @brief Verifies a signed file using GPG.
 *
 * This function checks if the GPG verification is ignored based on
 * the configuration. If not ignored, it verifies the signature of the
 * specified file using the provided keyring.
 *
 * @param path The path to the signed file to be verified.
 * @param keyring The path to the GPG keyring to be used for verification.
 * @return true if the file signature is valid, false otherwise.
 */
bool verify_file(const char *path, const char* keyring);

#endif
