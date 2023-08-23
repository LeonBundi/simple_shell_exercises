#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prompt with getline
 *
 * Return: Always 0.
 */
int main()
{
	char *line = NULL;
	size_t len = 0;

	printf("$ ");
	getline(&line, &len, stdin);

	printf("You entered: %s", line);


	free(line);

	return 0;
}

