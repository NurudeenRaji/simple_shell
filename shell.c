#include "shell.h"
#define MAX_LIMIT 32

int main(int argc, char *argv[])
{
	char *entry = (char *)malloc(MAX_LIMIT * sizeof(char));
	size_t vol = MAX_LIMIT;


	while (1)
	{
		shell_interpreter(entry, vol);
		handle_arg(entry, vol);
		handle_path(argc, argv);
		if (strcmp(entry, "exit") == 0) {
			break;
		}
	}


	return (0);
}
