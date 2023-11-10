#include "shell.h"

int main(int ac, char **av)
{
	char *input = NULL;
	size_t size = 0;

	(void)ac;
	(void)av;

	while (true)
	{
		shell_prompt();
		shell_interpreter(input, size);
	}

	return (0);
}
