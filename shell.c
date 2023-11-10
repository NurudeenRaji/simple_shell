#include "shell.h"


int main(int ac, char **av)
{
	size_t size = 0;
	char *entry = NULL;

	(void)ac;
	(void)av;

	while (true)
	{
		shell_display();	
		shell_interpreter(entry, size);
		/*shell_execute(entry);*/

	}
	free(entry);

	return (0);
}
