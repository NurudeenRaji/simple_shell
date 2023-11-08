#include "shell.h"

#define MAX_LIMIT 64

void shell_interpreter(char *entry, size_t vol);

/**
 * shell_interpreter - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size o9f command
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
		if (entry[strlen(entry) - 1] == '\n')
			break;
		i = 0;
		/*entry[strcspn(entry, "\n")] = '\0';*/
		token = strtok(entry, " ");
		if (token == NULL)
			continue;
		while (token != NULL)
		{
			argv[i] = token;
			i++;
			token = strtok(NULL, " ");
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
			char *envp[] = {NULL};

			if (execve(argv[0], argv, envp) < 0)
			{
				perror("shell");
				free(entry);
				exit(1);
			}
		}
		else
			waitpid(pid, &status, 0);

		printf("#raji_manass!$ ");
	}
}
