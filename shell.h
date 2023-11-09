#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>

void shell_interpreter(char *entry, size_t vol);
void shell_prompt(void);
void handle_arg(char *entry, size_t vol);
void handle_path(int argc, char *argv[]);

#endif
