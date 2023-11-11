#include "shell.h"

void exit_shell(char **args)
{

	if (args != NULL && args[0] != NULL)
        {
		if (strcmp(args[0], "exit") == 0)
		{
			exit(1);
		}
	}
}
