#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the environment
 *
 * @ac: argument counter
 * @av: argument vector
 * @env: variable
 * @environ: global variable
 *
 * Return: Always 0.
 */
extern char **environ;

int main(int ac, char **av, char **env)
{
	printf("Address of env: %p\n", (void*)env);
	printf("Address of environ: %p\n", (void*)environ);

	return 0;
}

