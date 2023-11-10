#include "shell.h"

void shell_display(void)
{
        if (isatty(STDIN_FILENO))
        {
                printf("#Raji~Manass!$ ");
        }
}
