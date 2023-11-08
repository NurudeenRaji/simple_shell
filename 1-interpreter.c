 #include "shell.h"

#define MAX_LIMIT 100

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
		if (strcspn(entry, "exit") == 0)
		{
			free(entry);
			return;
		}
		token = strtok(entry, " ");
		while (token != NULL)
		{
			i = 0;
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
			execve(args[0], args, NULL);
			perror("./shs");
			free(entry);
			exit(1);
		}
		else
			waitpid(pid, &status, 0);

		printf("#Raji~Manass!$ ");
	}
}
