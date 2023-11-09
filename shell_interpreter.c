#include "shell.h"

#define MAX_LIMIT 256

void shell_interpreter(char *entry, size_t vol);

/**
 * shell_interpreter - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size of command
 */

void shell_interpreter(char *entry, size_t vol)
{       
	char *args[MAX_LIMIT];
	char *token;
	pid_t pid;
	int i, status;

	if (isatty(STDIN_FILENO))
	{
		printf("#Raji~Manass!$ ");
	}
	if (getline(&entry, &vol, stdin) == EOF)
	{
		free(entry);
		exit(1);
	}
	entry[strcspn(entry, "\n")] = 0;
	if (strcspn(entry, "exit") == 0)
	{
		free(entry);
		return;
	}

	token = strtok(entry, " ");
	i = 0;
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	pid = fork();

	if (pid < 0)
	{
		perror("fork");
		free(entry);
		exit(1);
	}
	else if (pid == 0)
	{
		int fd = dup(1);
		close(1);
		if (dup2(fd,1) == -1)
		{
			perror("dup2");
			free(entry);
			exit(1);
		}
		execve(args[0], args, NULL);
		perror("./shell");
		free(entry);
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(entry);
	}
}
