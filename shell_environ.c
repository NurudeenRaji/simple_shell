#include "shell.h"

/**
 * print_env - A function that get the environment
 * @args: An input argument
 */

extern char **environ;

void print_env(char **args)
{
	int i, j;
	char **env = environ;

	j = 0;
	while (args != NULL && args[j] != NULL)
	{
		if (strcmp(args[j], "env") == 0)
		{
			i = 0;
			while (env[i] != NULL)
			{
				printf("%s\n", env[i]);
				i++;
			}
		}
		j++;
	}
}
