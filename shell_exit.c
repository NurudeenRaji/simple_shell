#include "shell.h"

void exit_shell(char **args)
{
	int status;

	if (args != NULL && args[0] != NULL)
        {
		if (strcmp(args[0], "exit") == 0)
		{
			status = 0;
			if (args[1] != NULL)
			{
				status = atoi(args[1]);
			}
			exit(status);
		}
	}
}
