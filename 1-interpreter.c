#include "shell.h"

#define MAX_LIMIT 32
extern char **environ;

/**
 * shell_interpreter - Interpretes user input from shell input.
 */

void shell_interpreter(char *entry, size_t vol)
{
	int status, i;
	char *token;
	char *argv[MAX_LIMIT];
	pid_t pid;

	printf("#raji_manass!$ ");
	while(getline(&entry, &vol, stdin) != EOF)
	{
		token = strtok(entry, " \n");
		while (token != NULL)
		{
			argv[i] = token;
			i++;
			token = strtok(NULL, " \n");
		}
		argv[i] = NULL;

		pid = fork();

		if (pid < 0)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(argv[0], argv, environ) == -1)
			{
				perror("execve");
				free(entry);
				exit(1);
			}
		}
		else
			waitpid(pid, &status, 0);

		printf("#raji_manass!$ ");
	}
}
