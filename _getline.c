#include "shell.h"

#define BUFFER_SIZE 1024

char _getline(void)
{
	static char buffer[BUFFER_SIZE];
	static char *location;
	static int chars;

	if (chars == 0)
	{
		chars = read(buffer);
		location = buffer;
	}

	for (i = 0; i < location; i++)
	{
		if (
