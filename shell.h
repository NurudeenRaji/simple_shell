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

void _print(const char *str);
void shell_prompt(void);
char **shell_input(char *entry, size_t vol, char **env);
void shell_execute(char **args, char **env);
char *handle_path(char *entry);
void print_env(char **args, char **env);
void exit_shell(char **args);
ssize_t _getline(char **line, size_t *n, FILE *stream);

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_memcpy(char *dest, char *src, unsigned  int n);
unsigned int _strcspn(char *s, char *reject);
char *_strdup(char *str);
int _strlen(const char *s);
int _putchar(char c);
void _puts(char *str);

#endif
