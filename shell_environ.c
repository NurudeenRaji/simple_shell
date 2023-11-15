#include "shell.h"

/**
 * print_env - A function that print the environment
 * @args: An input argument
 * @env: the environment variable from main function.
 */

void print_env(char **args, char **env)
{
	int i, j;
	const char *var;
	size_t len;

	j = 0;
	while (args != NULL && args[j] != NULL)
	{
		if (_strcmp(args[j], "env") == 0)
		{
			i = 0;
			while (env[i] != NULL)
			{
				var = env[i];
				len = _strlen(var);
				write(STDOUT_FILENO, var, len);
				write(STDOUT_FILENO, "\n", 1);
				i++;
			}
		}
		j++;
	}
}
