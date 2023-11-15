#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * _getline - A function thatget a line fro a giving input
 * @line: A string input line
 * @stream: File to stream path from
 * @n: Number of a giving input
 * Return: Size of input
 */

ssize_t _getline(char **line, size_t *n, FILE *stream);

ssize_t _getline(char **line, size_t *n, FILE *stream)
{
	static char buffer[BUFFER_SIZE];
	static int index;
	static int buffer_read;
	ssize_t size;
	char *temp;
	int newline;

	index = 0;
	buffer_read = 0;
	size = 0;

	if (line == NULL || n == NULL || stream == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	if (*line == NULL || *n == 0)
	{
		*n = BUFFER_SIZE;
		*line = malloc(*n);
		if (*line == NULL)
			return (-1);
	}

	while (true)
	{
		if (index >= buffer_read)
		{
			buffer_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
		if (buffer_read <= 0)
			break;
		index = 0;
		}

		if (buffer_read == -1)
			return (-1);
		while (index < buffer_read)
		{
			if ((size_t)size >= *n - 1)
			{
				*n *= 2;
				temp = realloc(*line, *n);
				if (temp == NULL)
					return (-1);
				*line = temp;
			}
			(*line)[size++] = buffer[index++];

			if (buffer[index - 1] == '\n')
			{
				newline = 1;
				break;
			}
		}

		if (newline || buffer_read == 0)
			break;
	}

	(*line)[size] = '\0';

	if (size == 0 && buffer_read <= 0)
		return (-1);

	return (size);
}
