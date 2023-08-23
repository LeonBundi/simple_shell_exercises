#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _setenv(const char *name, const char *value, int overwrite) {
    if (name == NULL || *name == '\0' || strchr(name, '=') != NULL) {
        return -1;  /* Invalid input */
    }

    size_t name_length = strlen(name);
    size_t value_length = strlen(value);
    size_t entry_length = name_length + value_length + 2;  /* +1 for '=' and +1 for null terminator */

    char *new_entry = (char *)malloc(entry_length);
    if (new_entry == NULL) {
        perror("Memory allocation failed");
        return -1;
    }

    /* Create the new entry */
    snprintf(new_entry, entry_length, "%s=%s", name, value);

    /* Check if the variable already exists */
    for (int i = 0; environ[i] != NULL; i++) {
        if (strncmp(environ[i], name, name_length) == 0 && environ[i][name_length] == '=') {
            if (overwrite) {
                /* Update the existing variable */
                free(environ[i]);
                environ[i] = new_entry;
                return 0;
            } else {
                free(new_entry);
                return 0;  /* No overwrite, return success */
            }
        }
    }

    /* Variable doesn't exist, add it */
    int env_size = 0;
    while (environ[env_size] != NULL) {
        env_size++;
    }

    char **new_environ = (char **)malloc((env_size + 2) * sizeof(char *));
    if (new_environ == NULL) {
        perror("Memory allocation failed");
        free(new_entry);
        return -1;
    }

    for (int i = 0; i < env_size; i++) {
        new_environ[i] = environ[i];
    }

    new_environ[env_size] = new_entry;
    new_environ[env_size + 1] = NULL;

    environ = new_environ;

    return 0;
}

int main() {
    const char *var_name = "MY_VARIABLE";
    const char *var_value = "new_value";

    /* Add or change the environment variable */
    if (_setenv(var_name, var_value, 1) == 0) {
        printf("%s=%s added/changed successfully.\n", var_name, var_value);
    } else {
        printf("Failed to add/change %s=%s.\n", var_name, var_value);
    }

    /* Print the updated environment */
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}

