#include "shell.h"

#define MAX_LIMIT 30
extern char **environ;

void handle_arg(char *entry, size_t vol);

/**
 * handle_arg - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size of command
 */

void handle_arg(char *entry, size_t vol)
{
	int status, i;
	char *token;
	char *args[MAX_LIMIT];
	pid_t pid;

	printf("#Raji~Manass!$ ");
	while (1)
	{
		if (getline(&entry, &vol, stdin) == EOF)
		{
			printf("\n");
			free(entry);
			exit(1);
		}
		entry[strcspn(entry, "\n")] = 0;
		if (strcmp(entry, "exit") == 0)
		{
			free(entry);
			exit(0);
		}
		if (entry[0] == '\0')
		{
			continue;
		}
		i = 0;
		token = strtok(entry, " ");
		while (token != NULL)
		{
			if (i >= MAX_LIMIT)
			{
				printf("Too many agument\n");
				break;
			}
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;
		pid = fork();

		if (pid < -1)
		{
			perror("fork");
			free(entry);
			exit(1);
		}
		else if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("execve");
				free(entry);
				exit(1);
			}
		}
		else
			waitpid(pid, &status, 0);
		 printf("#Raji~Manass!$ ");
	}
}
