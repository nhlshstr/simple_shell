#include "holberton.h"
/**
 *
 *
 *
 */
char **tokenizePath(char *inPath)
{
        int i = 0, count;
        char *token;
        char **outArr;
        char *copy_src = _strdup(inPath);

        token = strtok(copy_src, ":");
        while (token != NULL)
        {
                token = strtok(NULL, ":");
                count++;
        }

        outArr = malloc(sizeof(char *) * (count + 1));
        token = strtok(inPath, ":");
        while(token != NULL)
        {
		outArr[i] = token;
		token = strtok(NULL, ":");
		i++;
        }

        outArr[count] = NULL;
        return (outArr);
}
