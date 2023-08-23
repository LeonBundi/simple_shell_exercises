#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

int _unsetenv(const char *name) {
    if (name == NULL || *name == '\0' || strchr(name, '=') != NULL) {
        return -1;  /* Invalid input */
    }

    int found = 0;

    for (int i = 0; environ[i] != NULL; i++) {
        if (strncmp(environ[i], name, strlen(name)) == 0 && environ[i][strlen(name)] == '=') {
            free(environ[i]);
            found = 1;

            /* Shift the remaining entries to fill the gap */
            for (int j = i; environ[j] != NULL; j++) {
                environ[j] = environ[j + 1];
            }
        }
    }

    return found ? 0 : -1;
}

int main() {
    const char *var_name = "MY_VARIABLE";

    /* Delete the environment variable */
    if (_unsetenv(var_name) == 0) {
        printf("%s removed successfully.\n", var_name);
    } else {
        printf("Failed to remove %s.\n", var_name);
    }

    /* Print the updated environment */
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }

    return 0;
}

