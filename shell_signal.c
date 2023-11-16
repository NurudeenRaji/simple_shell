#include "shell.h"

void signal_handler(int sig __attribute__((unused)));

int sigint = 0;

/**
 * signal_handler - Handles the signal.
 * @sig: Not used.
 */

void signal_handler(int sig __attribute__((unused)))
{
	sigint = 1;
	write(STDOUT_FILENO, "\n", 1);
	exit(EXIT_SUCCESS);
}
