#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * find_file_in_path - string to generate PATH
 *
 * @filename: token pointer
 *
 * Return: Always 0.
 */
char* find_file_in_path(const char* filename)
{
	char* path_env = getenv("PATH");

	if (!path_env)
	{
		return NULL;
	}

	char* path_copy = strdup(path_env);

	if (!path_copy)
	{
		return NULL;
	}

	char* path = strtok(path_copy, ":");

	while (path != NULL)
	{
		char file_path[1024];

		snprintf(file_path, sizeof(file_path), "%s/%s", path, filename);

		struct stat file_info;

		if (stat(file_path, &file_info) == 0)
		{
			if (S_ISREG(file_info.st_mode))
			{
				free(path_copy);
				return strdup(file_path);
			}
		}

		path = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}

/**
 * main - return result
 *
 *@argc: argument counter
 *@argv: argument vector
 *
 * Return: Always 0.
 */
int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("Usage: %s _which filename ...\n", argv[0]);
		return 1;
	}

	for (int i = 1; i < argc; ++i)
	{
		char* file_path = find_file_in_path(argv[i]);

		if (file_path)
		{
			printf("%s\n", file_path);
			free(file_path);
		}
		else
		{
			printf("%s not found in PATH.\n", argv[i]);
		}
	}

	return 0;
}

