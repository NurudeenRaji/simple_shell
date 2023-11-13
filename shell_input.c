#include "shell.h"

void shell_input(char *entry, size_t vol);

/**
 * shell_interpreter - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size of command
 */

void shell_input(char *entry, size_t vol)
{
	char **args, *token, *entry_copy;
	ssize_t output;
	int i, j, count;

	output = getline(&entry, &vol, stdin);
	if (output == EOF)
		exit(1);

	entry[strcspn(entry, "\n")] = '\0';

	if (entry[0] == '\0')
	{
		return;
	}

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
		args[i] = malloc(sizeof(char *) * (strlen(token) + 1));
		strcpy(args[i], token);
		exit_shell(args);
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	shell_execute(args);
	print_env(args);
	/*exit_shell(args);*/

	free(entry);
	free(entry_copy);
	for (j = 0; j < i; j++)
		free(args[j]);
	free(args);
}
