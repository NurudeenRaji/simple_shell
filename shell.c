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
	size_t size = 0;

	(void)ac;
	(void)av;

	while (true)
	{
		shell_prompt();
		shell_input(input, size, env);

		free(input);
		input = NULL;
	}

	return (0);
}
