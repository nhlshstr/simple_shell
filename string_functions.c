#include "holberton.h"
/**
 *_strdup - returns pointer to a newly allocated space
 *
 * @str: string which is to be copied
 *
 * Return: NULL if allocation fails, or if string is empty
 *		pointer to duplicate string otherwise.
 */
char *_strdup(char *str)
{
	unsigned int count, i;
	char *dest;

	if (str == NULL)
		return (NULL);

	for (count = 0; str[count] != '\0'; count++)
	{
		;
	}

	dest = malloc((sizeof(char) * count) + 1);

	if (dest == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
	{
		dest[i] = str[i];
	}

	dest[i] = '\0';

	return (dest);
}


