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

/**
 * _strcat - main function for concatenation
 * @dest: destination file
 * @src: string to be appended
 * Return: dest
 */
char *_strcat(char *dest, char *src)

{

	int a, b;

	for (b = 0; dest[b] != '\0'; b++)
		;
	for (a = 0; src[a] != '\0'; a++, b++)
	{
		dest[b] = src[a];
	}
	src[a] = '\0';
	return (dest);
}

/**
 * _strcmp - main function
 * @s1: first stirng
 * @s2: second string
 * Return: -, or 0
 */
int _strcmp(char *s1, char *s2)

{

	int a;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)

		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
	return (0);
}
