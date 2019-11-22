#include "holberton.h"
/**
 *main - Driver function for UNIX interpreter
 *
 *
 *Return: Returns (0) if successful, otherwise accoridng error.
 */
int main(int argc, char **argv, char **env)
{
		char *src = NULL, **arr = NULL;
		size_t src_size = 0;
		int check = 0, execCheck = 0, status;
		(void)argc;
		(void)env;
		while (check != -1)
		{
			if(isatty (STDIN_FILENO))
				_printR("[(xshell$)] ");
			check = getline(&src, &src_size, stdin);
			src = newLine(src);
			if (check == EOF)
			{		
					printf("\n");
					exit(EXIT_SUCCESS);
			}
			//if (check == -1)
			//		break;
			if (check == 1)
					continue;
			arr = _tokenize(src);
			if (fork() == 0)
			{
				execCheck =	execve(arr[0], arr, NULL);
				if (execCheck == -1)
				{
					printf("%s: No such file or directory\n", argv[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
				wait(&status);
		}

		free(arr);
		return (0);
}
/**
 *
 *
 */
int _printR(char *str)
{
	int count;
	int val;

	for (count = 0; str[count]; count++)
		;

	val = write(STDOUT_FILENO, str, count);

	if (val != count)
	{
		write(STDERR_FILENO, "Write Error\n", 12);
		exit(EXIT_FAILURE);
	}

	return (val);
}
/**
 *
 *
 */
char *newLine(char *src)
{	
	int j = 0;	

	for (j = 0; src[j] != '\0'; ++j)
		{
			if (src[j] == '\n'|| src[j + 1] == '\0')
				src[j] = '\0';
		}
	return (src);
}




