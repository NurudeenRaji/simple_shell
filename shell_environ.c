#include "shell.h"

void shl_env(void)
{
	char *entry;
	int flag = 1;
	char **ev = environ;

	while (*env)
	{
		printf("\n", *env++);
	}
	while (flag == 1)
	{
		call prompt;
		geline(&entry, &len, stdin);
		if (strcmp(entry, "env\n") == 0)
		{
			shl_vnv();
		}
	}
}

