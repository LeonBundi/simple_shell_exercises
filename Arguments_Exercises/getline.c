#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - getline function
 *
 * Return: Always 0.
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return -1;
	}

	size_t bufferSize = *n;
	size_t bytesRead = 0;
	int character;

	/* Allocate initial buffer if needed */
	if (*lineptr == NULL || *n == 0)
	{
		*n = 128;  /* Initial buffer size */

		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return -1; /* Memory allocation failure */
		}
	}

	/* Read characters from stream until newline or end-of-file */
	while ((character = fgetc(stream)) != EOF)
	{
		/* Resize buffer if needed */
		if (bytesRead + 1 >= bufferSize)
		{
			bufferSize *= 2;

			char *newBuffer = (char *)realloc(*lineptr, bufferSize);

			if (newBuffer == NULL)
			{
				return -1; /* Memory reallocation failure */
			}
			*lineptr = newBuffer;
			*n = bufferSize;
		}
		(*lineptr)[bytesRead++] = character;

		if (character == '\n')
		{
			break; /* Stop reading at newline */
		}
	}
	if (bytesRead == 0)
	{
		return -1; /* No data read (end-of-file or error) */
	}
	(*lineptr)[bytesRead] = '\0'; /* Null-terminate the string */
	return bytesRead;
}

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

