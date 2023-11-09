#include "shell.h"

void shell_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		printf("#Raji~Manass!$ ");
	}
}
