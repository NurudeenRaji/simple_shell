#include "shell.h"

/**
 * _strlen - Length of a string.
 * @s: the string.
 * Return: string count.
 */

int _strlen(const char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}

	return (count);
}

/**
 * _memcpy - Copies memory area.
 * @dest: the destination memory.
 * @src:  the source memory.
 * @n: the bytes of memory to copy from the source.
 * Return: pointer to the destination.
 */


char *_memcpy(char *dest, char *src, unsigned  int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}

/**
 * _strcspn - Gets the length of a prefix substring.
 * @s: the string to check through.
 * @reject: the prefix to check.
 * Return: number of bytes from accept in s.
 */

unsigned int _strcspn(char *s, char *reject)
{
	unsigned int i, j;

	i = 0;
	while (s[i])
	{
		for  (j = 0; reject[j]; j++)
		{
			if (s[i] == reject[j])
			{
				return (i);
			}
		}
		i++;
	}
	return (i);
}

/**
 * _atoi - coverts string to integer
 * @str: the string to be converted
 * Return: the integer
 */

int _atoi(char *str)
{
	int result = 0, sign = 1, i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		++i;
	}

	return (sign * result);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
