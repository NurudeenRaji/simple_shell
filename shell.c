#include "shell.h"

#define MAX_LIMIT 32

int main(void)
{
	char *entry = NULL; /*(char *)malloc(MAX_LIMIT * sizeof(char));*/
	size_t vol = 0;/*MAX_LIMIT;*/

	while (1)
	{
		shell_prompt();
		shell_interpreter(entry, vol);
	}
	return (0);
}
