#include "shell.h"

#include MAX_CMD 50


void no_tork(void)
{
	char entry[1024];
	char args[MAX_CMD];
	int vol_args = 0;

	while (1)
	{
		call the prompt;
		entry[strcspn(entry, "\n")] = '\n';
		args[vol_args] = strtok(entry, " ");
		while (args[vol_args] != NULL && vol_args < MAX_CMD - 1)
		{
			vol_args++;
			args[vol_args] = strtok(NULL, " ");
		}
		arg[vol_args] = NULL;
	}
}
