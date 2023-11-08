#include "shell.h"

int main(void)
{
	char *entry = NULL;
	size_t size = 0;

	while (true)
	{
		shell_interpreter(entry, size);
	}


	return (0);
}
