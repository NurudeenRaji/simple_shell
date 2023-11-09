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

void shell_prompt(void);
void shell_interpreter(char *entry, size_t vol);
void handle_path(char *entry, size_t len);

#endif
