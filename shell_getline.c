#include "shell.h"

char getline_shell()
{
        static cmd_line[1024];
        static location = 0;
        int x;

        while ((c = getchar()) != '\n' && c != EOF)
        {
                if (location < sizeof(cmd_line) - 1)
                {
                        cmd_line[location++] = x
                }
        }
        cmd_line[] = '\n';

        location = 0;

        return(cmd_line);
}
