#include "shell.h"

void shell_interpreter(char *entry, size_t vol);
void shell_execute(char **args);

/**
 * shell_interpreter - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size of command
 */

void shell_interpreter(char *entry, size_t vol)
{
	char **args;
	char *token, *entry_copy;
	ssize_t output;
	int i, j, count;

	output = getline(&entry, &vol, stdin);
	if (output == EOF)
		exit(1);

	entry[strcspn(entry, "\n")] = '\0';

	entry_copy = strdup(entry);

	token = strtok(entry, " ");
	count = 0;
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	count++;
	args = malloc(sizeof(char *) * count);
	token = strtok(entry_copy, " ");
	i = 0;
	while (token != NULL)
	{
		/*args[i] = token;*/
		args[i] = malloc(sizeof(char *) * (strlen(token) + 1));
		strcpy(args[i], token);
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	shell_execute(args);
	free(entry);
	free(entry_copy);
	for (j = 0; j < i; j++)
		free(args[j]);
	free(args);
}

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
