#include "shell.h"

char *handle_path(char *entry);

char *handle_path(char *entry)
{
	char *path, *path_dup, *dir, *new_path;
	struct stat check;


	path = getenv("PATH");
	if (path)
	{
		path_dup = strdup(path);
		dir = strtok(path_dup, ":");

		while (dir != NULL)
		{
			new_path = malloc(strlen(dir) + strlen(entry) + 2);
			if (new_path == NULL)
				return (NULL);
			strcpy(new_path, dir);
			strcat(new_path, "/");
			strcat(new_path, entry);
			strcat(new_path, "\0");

			if (stat(new_path, &check) == 0)
			{
				free(path_dup);
				return(new_path);
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
				return (entry);
			}
		return (NULL);
	}
	return (NULL);
}
