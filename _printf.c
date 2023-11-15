#include "shell.h"

void _printf(const char *str)
{
	write(STDOUT_FILENO, str, strlen(str));
}
