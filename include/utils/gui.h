/**
 * @brief Displays a Yes/No dialog box with a specified title and message.
 *
 * This function presents a dialog to the user that allows them to make a
 * response of "Yes" or "No". The dialog is typically used for confirming
 * actions or decisions that require user input.
 *
 * @param title A string representing the title of the dialog window. This
 *              will be displayed prominently at the top of the dialog.
 * @param message A string containing the message to be displayed in the
 *                dialog. This should provide context for the user's
 *                decision.
 *
 * @return Returns true if the user selects "Yes", or false if the user
 *         selects "No".
 *
 */
bool yes_no_dialog(const char* title, const char *message);
