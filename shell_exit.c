#include "shell.h"

void quit_shell(int quit)
{
	char entry;

	if (strcmp(entry, "exit\n") == 0)
	{
		exit_shell(quit);
	}
	exit(1);
}
