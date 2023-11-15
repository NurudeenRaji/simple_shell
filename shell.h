#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

void shell_prompt(void);
char **shell_input(char *entry, size_t vol);
void shell_execute(char **args);
char *handle_path(char *entry);
void print_env(char **args, char **env);
void exit_shell(char **args);
ssize_t _getline(char **line, size_t *n, FILE *stream);

#endif
