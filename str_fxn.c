#include "shell.h"

/**
 * _strcpy - Copies a string
 * @dest: Destination for pasting.
 * @src: Source of copy.
 * Return: pointer to dest.
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: 0(Succes), 1(Error).
 */

int _strcmp(char *s1, char *s2)
{
	int i, check, diff;

	check = 0;
	for (i = 0; s1[i] != '\0' && s2[i] != '\0';  i++)
	{
		if (s1[i] != s2[i])
		{
			check = 1;
			break;
		}
	}

	if (check == 1)
	{
		diff = s1[i] - s2[i];
	}
	else
		return (0);

	return (diff);
}


/**
 * _strcat - Concatenates two strings.
 * @dest: Destination string.
 * @src: Source string.
 * Return: return a pointer to the resulting string.
 */

char *_strcat(char *dest, char *src)
{
	int i, len1, len2, j, k;

	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	len1 =  i;
	for (j = 0; src[j] != '\0'; j++)
	{
	}
	len2 = j;

	for (k = 0; k <= len2; k++)
	{
		dest[len1 + k] = src[k];
	}

	dest[len1 + len2] = '\0';

	return (dest);
}

/**
 * _strdup - Duplicates a string.
 * @str: String to be duplicated.
 * Return: the new  string.
 */

char *_strdup(char *str)
{
	char *new_str;
	size_t length;

	length	= _strlen(str) +  1;
	new_str = malloc(length);

	if (new_str == NULL)
		return (NULL);
	_memcpy(new_str, str, length);

	return (new_str);
}


