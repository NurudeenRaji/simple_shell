#include "shell.h"

void handle_path(char *entry, size_t len);

void handle_path(char *entry, size_t len)
{
	char *path, *dr, *entry[] = "";
	size_t len = 0;
	int status, flag = 1;
	pid_t pid;

	while (flag == 1)
	{
		shell_prompt();
		getline(&entry, &len, stdin);
		entry[strcspn(entry, '\n')] = '\0';
		path = getenv("PATH");
		dr =strtok(path, ":");
		while (dr != NULL)
		{
			char *f_path= malloc(strlen(dr) + strlen(entry) + 2);
			strcpy(f_path, dr);
			strcat(f_path, "/");
			strcat(f_path, entry);
			if (access(f_path, X_OK) == 0)
			{
				pid = fork();
				if (pid == -1)
				{
					perror("Error:");
					return (1);
				}
				if (pid == 0)
				{
					if (execve(f_path, entry, NULL) == -1)
					{
						perror("Error:");
					}
				}
				else
				{
					wait(&status);
				}
				free(f_path);
				break;
			}
			free(f_path);
			dr = strtok(NULL, ":");
		}
	}
}
