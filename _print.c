#include "shell.h"

/**
 * _print - Prints a string.
 * @str: the string to print.
 */

void _print(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
