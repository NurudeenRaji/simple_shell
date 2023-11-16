#include "shell.h"

char **shell_input(char *entry, size_t vol, char **env);

/**
 * shell_input - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size of command
 *
 * Return: return the processed input;
 */

char **shell_input(char *entry, size_t vol, char **env)
{
	char **args, *token, *entry_copy;
	ssize_t output;
	int i, count;

	output = getline(&entry, &vol, stdin);
	if (output == -1)
	{
		free(entry);
		return (NULL);
	}

	entry[_strcspn(entry, "\n")] = '\0';

	if (entry[0] == '\0')
	{
		return (NULL);
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

	shell_execute(args, env);

	return (args);
}
