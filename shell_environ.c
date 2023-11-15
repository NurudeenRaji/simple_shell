#include "shell.h"

/**
 * print_env - A function that print the environment
 * @args: An input argument
 */

int  print_env(int argc, char **argv, char **environ)
{
	while (argc == 2 && strcmp(argv[1], "env") = 0)
	{
		while (*environ != NULL)
		{
			printf("%s\n", *environ);
			environ++;
		}
	}
	else
	{
		printf("Err: invalid 'env'\n");
	}
	return (0);
}
