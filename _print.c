#include "shell.h"

/**
 * _print - Prints a string.
 * @str: the string to print.
 * @fd: file descriptor to indicate in, out or err.
 */

void _print(const char *str, int fd)
{
	write(fd, str, _strlen(str));
}
