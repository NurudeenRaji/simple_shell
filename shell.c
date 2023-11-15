#include "shell.h"

/**
 * main - A function that take all the input argument
 * frome all the progran function
 * @ac: An argument count
 * @av: An input argument value
 * Return: 0 success
 */

int main(int ac, char **av, char **env)
{
	char *input = NULL;
	char **args = NULL;
	size_t size = 0;

	(void)ac;
	(void)av;

	while (true)
	{
		shell_prompt();
		args = shell_input(input, size);
		print_env(args, env);

		free(input);
		free(args);
		args = NULL;
		input = NULL;
	}

	return (0);
}
