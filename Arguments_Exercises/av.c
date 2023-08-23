#include <stdio.h>
#include <stdlib.h>

/**
 * main - av with no ac
 *
 *@ac: is the number of items in av
 *@av: is a NULL terminated array of strings
 *
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	char **current_av = av;

	if (*current_av != NULL)
	{
		printf("Argument: %s\n", *current_av);
		current_av++;
	}
	else
	{
		return (-1);
	}
	while (*current_av != NULL)
	{
		int value = atoi(*current_av);

		printf("Argument as Integer: %d\n", value);
		current_av++;
	}

	return (0);
}

