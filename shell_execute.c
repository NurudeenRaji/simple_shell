#include "shell.h"

void shell_execute(char **args);

void shell_execute(char **args)
{
	pid_t pid;
	int status;

	char *entry = NULL;
	char *new_entry = NULL;

	if (args != NULL)
	{
		entry = args[0];
	}

	if (entry != NULL)
		new_entry = handle_path(entry);

	pid = fork();

	if (pid < 0)
	{
		perror("Fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (new_entry != NULL)
		{
			if (execve(new_entry, args, NULL) == -1)
			{
				perror("Err:");
			}
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
