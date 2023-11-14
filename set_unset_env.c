#include "shell.h"

extern char **environ;

void _un_set_env()
{
	char **env = environ;
	char *entry, *id, *val;
	int states;

	call input
	if (strncmp(entry, "setenv", 6) == 0)
	{
		id = strtok(entry + 7, " ");
		val= strtok(NULL, " ");
		if (val != NULL)
		{
			if (setenv(id, val, 1) != 0)
			{
				perror("Err:");
			}
		}
		else
		{
			fprintf(stderr, "Err: setenv only two args\n")
		}
	}
	else
	{
		pid_t pid;
		if (pid < 0)
		{
			perror("Err:");
		}
		else if (pid == 0)
		{
			char *upset[] = {"/bin/sh", "-c", entry, NULL};
			execve(upset[0], upset, env);
			perror("Err:");
			exit(1);
		}
		else
		{
			waitpid(pid, &states, 0);
		}
	}
}
