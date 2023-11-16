#include "shell.h"

/**
 * main - A function that take all the input argument
 * frome all the progran function
 * @ac: An argument count
 * @av: An input argument value
 * @env: An input enviroment
 * Return: 0 success
 */

int main(int ac, char **av, char **env)
{
	char *input = NULL;
	char **args = NULL;
	size_t size = 0;
	int i;

	(void)ac;
	(void)av;

	while (true)
	{
		shell_prompt();
		args = shell_input(input, size, env);

		if (args != NULL)
		{
			print_env(args, env);

			i = 0;
			while (args[i] != NULL)
			{
				free(args[i]);
				i++;
			}
			free(args);
		}
		else
		{
			free(input);
			break;
		}

		free(input);
		input = NULL;
	}

	return (0);
}
