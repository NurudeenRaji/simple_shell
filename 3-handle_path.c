#include "shell.h"

#define MAX_ARGS 10
#define MAX_LEN 1024

void handle_path(int argc, char *argv[]);

extern char **environ;

void handle_path(int argc, char *argv[])
{
	char *entry[MAX_ARGS];
	char *path;
	char *token;
	char len[MAX_LEN];
	int i, y;
	pid_t pid;

	if (argc < 2)
	{
		printf("Usage: %s command [args...]\n", argv[0]);
		exit(1);
	}
	i = 0;
	for (y = 1; y < argc && y < MAX_ARGS - 1; y++)
	{
		if (strcmp(argv[y], "-h") == 0 || strcmp(argv[y], "--help") == 0)
		{
			printf("Usage: %s command [args...]\n", argv[0]);
			exit(0);
		}
		else
		{
			entry[i] = argv[y];
			i++;
		}
	}
	entry[i] = NULL;
	path = getenv("PATH");
	token = strtok(path, ":");
	while (token != NULL)
	{
		snprintf(len, MAX_LEN, "%s/%s", token, entry[0]);
		if (access(len, X_OK) == 0)
		{
			break;
		}
		token = strtok(NULL, ":");
	}
	if (token == NULL)
	{
		printf("%s: command not found\n", entry[0]);
		exit(1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(len, entry, environ);
		perror("execve");
		exit(1);
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}
