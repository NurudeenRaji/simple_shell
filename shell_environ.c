#include "shell.h"

/**
 * print_env - A function that get the environment
 * @args: An input argument
 * @env: the environment variable from main function.
 */

void print_env(char **args, char **env)
{
	int i, j;

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

        /*free(args);*/
}
