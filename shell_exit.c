#include "shell.h"

/**
 * exit_shell - A function that exit a program when
 * the exit comand is giving as arguments.
 * @args: Argument giving
 */

void exit_shell(char **args)
{
	int status, j;

	if (args != NULL && args[0] != NULL)
	{
		if (_strcmp(args[0], "exit") == 0)
		{
			status = 0;
			if (args[1] != NULL)
			{
				status = _atoi(args[1]);
			}
			else
				status = 2;


			for (j = 0; j < 2; j++)
				free(args[j]);
			free(args);

			exit(status);
		}
	}
}
