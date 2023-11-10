#include "shell.h"


int main(void)
{
	size_t size = 0;
	char *entry = malloc(sizeof(char) * 1024);

	while (true)
	{
		shell_display();	
		entry = shell_interpreter(entry, size);
		shell_execute(entry);

	}


	return (0);
}
