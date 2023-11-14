#include "shell.h"

void shell_execute(char **args);

void shell_execute(char **args)
{
	pid_t pid;
	int status;

	char *entry = NULL;
	char *new_entry = NULL;

	exit_shell(args);

	if (args != NULL)
	{
		entry = args[0];
	}

	if (entry != NULL)
	{
		new_entry = handle_path(entry);
		if (new_entry == NULL)
		{
			fprintf(stderr, "hsh: Invalid command or '%s' path not handled!!! \n", entry);
			return;
		}
	}


	pid = fork();

	if (pid < 0)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (new_entry != NULL)
		{
			if (execve(new_entry, args, NULL) == -1)
			{
				perror("execve failed");
<<<<<<< HEAD
				free(new_entry);
=======
				/*free(new_entry);*/
>>>>>>> 66276c816f4c6fe1b6f3e9884f7e7fdbb118d3bb
				_exit(EXIT_FAILURE);
			}
			free(new_entry);
		}
	}
	else
	{
		free(new_entry);
		waitpid(pid, &status, 0);
		/*free(new_entry);*/
	}
}
