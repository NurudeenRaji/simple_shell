#include "shell.h"

char *handle_path(char *entry);

char *handle_path(char *entry)
{
	char *path, *dir, *new_path;
	struct stat check;


	path = getenv("PATH");
	dir = strtok(path, ":");

	while (dir != NULL)
	{
		char *new_path = malloc(strlen(dir) + strlen(entry) + 2);
		strcpy(new_path, dir);
		strcat(new_path, "/");
		strcat(new_path, entry);
		strcat(new_path, "\0");

		if (stat(new_path, &check) == 0)
		{
			free(path);
			return(new_path);
		}
		else
		{
			free(new_path);
			dir = strtok(NULL, ":");
		}
	}
}
