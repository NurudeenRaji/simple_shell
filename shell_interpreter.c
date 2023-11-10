#include "shell.h"

void shell_interpreter(char *entry, size_t vol);
void shell_execute(char **args);

/**
 * shell_interpreter - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size of command
 */

void shell_interpreter(char *entry, size_t vol)
{
        char **args;
        char *token;
        ssize_t output;
        int i;

        output = getline(&entry, &vol, stdin);
        if (output == EOF)
        {
                /*printf("\n");*/
                return;
        }
        entry[strcspn(entry, "\n")] = '\0';


        token = strtok(entry, " ");

        args = malloc(sizeof(char *) * strlen(entry));

        i = 0;
        while (token != NULL)
        {
                args[i] = token;
                i++;
                token = strtok(NULL, " ");
        }
        args[i] = NULL;

        shell_execute(args);
}

void shell_execute(char **args)
{
        pid_t pid;
        int status;

        char *entry = NULL;
	char *new_entry = NULL;

        if (args)
        {
                entry = args[0];
        }

	new_entry = handle_path(entry);

        pid = fork();

        if (pid < 0)
        {
                perror("fork");
                free(entry);
                exit(1);
        }
        else if (pid == 0)
        {
                execve(new_entry, args, NULL);
                perror("./shell");
                /*free(entry);*/
                exit(1);
        }
        else
        {
                waitpid(pid, &status, 0);
                /*free(entry);*/
        }
}
