#include "shell.h"

/**
 * shell_prompt - A function that prompt when the program is invoke
 */

void shell_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_print("#Raji~Manass!$ ");
	}
}
