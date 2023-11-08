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


#endif
