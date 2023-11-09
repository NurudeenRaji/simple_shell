#include "shell.h"

int main(void)
{
	char *input = NULL;
	size_t size = 0;

	while (true)
	{
		shell_prompt();
		shell_interpreter(input, size);
		handle_path(input, size);
	}

	return (0);
}
