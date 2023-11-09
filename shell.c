#include "shell.h"

int main(void)
{
	char *entry = NULL;
	size_t size = 0;

	while (true)
	{
		shell_display();
		entry = shell_interpreter(entry, size);
		shell_execute(entry);
	}


	return (0);
}
