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

	/* Count the number of occurrences of the delimiter */
	*count = 1;
	const char *ptr = input;
	while ((ptr = strstr(ptr, delimiter)) != NULL)
	{
		(*count)++;
		ptr += strlen(delimiter);
	}

	/* Allocate memory for the array of strings */
	char **result = (char **)malloc(*count * sizeof(char *));
	if (result == NULL)
	{
		return NULL;
	}

	/* Copy each token to the array */
	size_t index = 0;
	ptr = input;
	while ((ptr != NULL) && (index < *count))
	{
		const char *nextDelimiter = strstr(ptr, delimiter);
		size_t tokenLength = nextDelimiter ? (size_t)(nextDelimiter - ptr) : strlen(ptr);

	result[index] = (char *)malloc((tokenLength + 1) * sizeof(char));
	if (result[index] == NULL)
	{
		for (size_t i = 0; i < index; i++)
		{
			free(result[i]);
		}
		free(result);
		return NULL;
	}

	strncpy(result[index], ptr, tokenLength);
	result[index][tokenLength] = '\0';

	ptr = nextDelimiter ? (nextDelimiter + strlen(delimiter)) : NULL;
	index++;
	}

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

