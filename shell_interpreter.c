#include "shell.h"

#define MAX_LIMIT 128

void shell_interpreter(char *entry, size_t vol);
void shell_execute(char  *entry);

/**
 * shell_interpreter - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size of command
 */

char *shell_interpreter(char *entry, size_t vol)
{
	if (getline(&entry, &vol, stdin) == EOF)
	{
		printf("\n");
		free(entry);
		exit(1);
	}
	entry[strcspn(entry, "\n")] = '\0';
	if (strcspn(entry, "exit") == 0)
	{
		free(entry);
		return;
	}
	return (entry);
}

void shell_execute(char  *entry)
{
	char *args[MAX_LIMIT];
        char *token;
        pid_t pid;
        int i, status;

        token = strtok(entry, " ");
        i = 0;
	while (token != NULL)
        {
                args[i] = token;
		i++;
                token = strtok(NULL, " ");
        }
        args[1] = NULL;
        pid = fork();

        if (pid < 0)
        {
                perror("fork");
                free(entry);
                exit(1);
        }
        else if (pid == 0)
        {
                execve(args[0], args, NULL);
                perror("./shell");
                free(entry);
                exit(1);
        }
        else
                waitpid(pid, &status, 0);	
}
