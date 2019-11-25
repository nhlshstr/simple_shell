#include "holberton.h"
/**
 *checkBuiltIn - checks for the built in functions
 *
 * @array: Double array of pointers to i/p strings
 * @ENN: Pointer to pointers of environment variables
 *
 * Return: Returns nothing
 */
void checkBuiltIn(char **array, char **ENN)
{
	if (_strcmp("exit", array[0]) == 0)
	{
		free(array);
		exit(EXIT_SUCCESS);
	}

	if (_strcmp(array[0], "env") == 0)
	{
			printenv(ENN);
	}
}
/**
 *
 *
 *
 */
void printenv(char **ENNV)
{
		int i = 0;

		for (i = 0; ENNV[i] != NULL; i++)
		{
				_printR(ENNV[i]);
				_putchar('\n');
		}
}
