#include "shell.h"

void shell_interpreter(char *entry, size_t vol);

/**
 * shell_interpreter - Interpretes user input from shell input.
 * @entry: User input
 * @vol: Size of command
 */

void shell_interpreter(char *entry, size_t vol)
{
        char *args[2];
        char *token;
        pid_t pid;
        int status;

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

        token = strtok(entry, " ");
        while (token != NULL)
        {
                args[0] = token;
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
