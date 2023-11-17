#include "shell.h"

void shell_input(char *entry, size_t vol, char **env);

/**
 * shell_input - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size of command
 * @env: The environment to input.
 */

void shell_input(char *entry, size_t vol, char **env)
{
	char **args, *token, *entry_copy;
	ssize_t output;
	int i, j, count;

	output = getline(&entry, &vol, stdin);
	if (output == EOF)
	{
		free(entry);
		exit(0);
	}

	entry[_strcspn(entry, "\n")] = '\0';

	if (entry[0] == '\0')
	{
		free(entry);
		return;
	}

	entry_copy = _strdup(entry);
	if (entry_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}

	token = strtok(entry, " ");
	count = 0;
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, " ");
	}
	count++;
	args = malloc(sizeof(char *) * count);
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	token = strtok(entry_copy, " ");
	i = 0;
	while (token != NULL)
	{
		args[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (args[i] == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		_strcpy(args[i], token);
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	free(entry);
	free(entry_copy);

	print_env(args, env);
	shell_execute(args, env);

	j = 0;
	while (args[j] != NULL)
	{
		free(args[j]);
		j++;
	}
	free(args);
}
