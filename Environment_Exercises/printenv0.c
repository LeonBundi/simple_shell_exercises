#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the environment
 *
 * @environ: global variable
 *
 * Return: Always 0.
 */
extern char **environ;

int main()
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}

	return 0;
}

