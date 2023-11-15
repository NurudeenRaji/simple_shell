#include "shell.h"

/**
 * handle_path - A function that handle all the path arguments to the program
 * @entry: The user input entry
 * Return: NULL
 */

char *handle_path(char *entry);

char *handle_path(char *entry)
{
	char *path, *path_dup, *dir, *new_path;
	struct stat check;

	path = getenv("PATH");
	if (path)
	{
		path_dup = _strdup(path);
		if (path_dup == NULL)
		{
			perror("strdup");
			return (NULL);
		}

		dir = strtok(path_dup, ":");

		while (dir != NULL)
		{
			new_path = malloc(_strlen(dir) + _strlen(entry) + 2);
			if (new_path == NULL)
				return (NULL);
			_strcpy(new_path, dir);
			_strcat(new_path, "/");
			_strcat(new_path, entry);

			if (stat(new_path, &check) == 0)
			{
				free(path_dup);
				return (new_path);
			}
			else
			{
				free(new_path);
				dir = strtok(NULL, ":");
			}
		}

			free(path_dup);

			if (stat(entry, &check) == 0)
			{
				return (_strdup(entry));
			}

		return (NULL);
	}
	return (NULL);
}
