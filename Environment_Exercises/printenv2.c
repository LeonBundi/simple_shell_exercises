#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * _getenv -  iterates through the environ array
 *  and checks each environment variable entry
 *
 * @environ: global variable
 * @name: parameter to be manipulated
 *
 * Return: Always 0.
 */
extern char **environ;

char *_getenv(const char *name)
{
	char **env = environ;

	while (*env)
	{
		char *entry = *env;

		/* Find the position of '=' in the environment variable entry */
		char *equal_sign = strchr(entry, '=');

		/* Calculate the length of the variable name */
		size_t var_length = equal_sign - entry;

		/* Compare the variable name with the requested name */
		if (strncmp(entry, name, var_length) == 0 && name[var_length] == '\0')
		{
			/* Return the value of the environment variable */
			return equal_sign + 1;
		}

		env++;
	}

	/* Variable not found */
	return NULL;
}

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main()
{
	const char *var_name = "PATH";
	char *value = _getenv(var_name);

	if (value)
	{
		printf("%s=%s\n", var_name, value);
	}
	else
	{
		printf("%s not found\n", var_name);
	}

	return 0;
}

