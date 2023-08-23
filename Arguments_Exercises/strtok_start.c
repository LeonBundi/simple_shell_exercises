#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * splitString - function containing major arguments
 *
 *@input: arbitrary string to be keyed
 *@delimiter: separating syntax
 *@count: used by token whom parses input
 *
 * Return: Always 0.
 */
char** splitString(const char *input, const char *delimiter, size_t *count)
{
	if (input == NULL || delimiter == NULL || count == NULL)
	{
		return NULL;
	}

	char *inputCopy = strdup(input);
	if (inputCopy == NULL)
	{
		return NULL;
	}

	*count = 0;
	char *token = strtok(inputCopy, delimiter);
	while (token != NULL)
	{
		(*count)++;
		token = strtok(NULL, delimiter);
	}


	char **result = (char **)malloc(*count * sizeof(char *));
	if (result == NULL)
	{
		free(inputCopy);
		return NULL;
	}

	token = strtok(inputCopy, delimiter);
	for (size_t i = 0; i < *count; i++)
	{
		result[i] = strdup(token);
		token = strtok(NULL, delimiter);
	}

	free(inputCopy);
	return result;
}

/**
 * main - contain argc and argv pointer
 *
 *@argc: integer that indicating no. of arguments when program started
 *@argv: an array of pointers to arrays of character objects
 *	 (argument vector)
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Usage: %s <input_string> <delimiter>\n", argv[0]);
		return 1;
	}

	const char *input = argv[1];
	const char *delimiter = argv[2];

	size_t count = 0;
	char **words = splitString(input, delimiter, &count);

	if (words != NULL)
	{
		for (size_t i = 0; i < count; i++)
		{
			printf("Word %zu: %s\n", i + 1, words[i]);
			free(words[i]);
		}
	free(words);
	}

	return 0;
}

