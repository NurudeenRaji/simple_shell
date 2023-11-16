#include "shell.h"

/**
 * shell_execute - A function that exicute a giving argument
 * @args: A giving arguments to exicute
 * @env: The environment to execute
 */

void shell_execute(char **args, char **env);

void shell_execute(char **args, char **env)
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
			perror("./shell");
			return;
		}
	}

	pid = fork();

	if (pid < 0)
	{
		perror("Fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (new_entry != NULL)
		{
			if (execve(new_entry, args, env) == -1)
			{
				perror("execve failed");
				free(new_entry);
				_exit(EXIT_FAILURE);
			}
			/*free(new_entry);*/
		}
	}
	else
	{
		free(new_entry);
		waitpid(pid, &status, 0);
	}
}
