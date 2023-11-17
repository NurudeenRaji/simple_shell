#include "shell.h"

/**
 * _print - Prints a string.
 * @str: the string to print.
 * @fd: file descriptor to indicate in, out or err.
 */

void _print(const char *str)
{
	write(STDOUT_FILENO, str, _strlen(str));
}
