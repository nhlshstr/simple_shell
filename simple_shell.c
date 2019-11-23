#include "holberton.h"
/**
 *main - Driver function for UNIX interpreter
 *
 *
 *Return: Returns (0) if successful, otherwise accoridng error.
 */
int main(int argc, char **argv, char **env)
{
		char *src = NULL;
		char **arr = NULL;
		size_t src_size = 0;
		int check = 0;
		(void)argc;
		(void)argv;
		
		while (check != -1)
		{	
			if(isatty(STDIN_FILENO))
				_printR("[(xshell$)] ");
			check = getline(&src, &src_size, stdin);
			src = newLine(src);
			if (check == EOF)
			{		
					printf("\n");
					exit(EXIT_SUCCESS);
			}
			if (check == 1)
					continue;
			arr = _tokenize(src);
			
			getDirs(arr, env);
			
			free(arr);
			
		}

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
/**
 *
 *
 */
void getDirs(char **input, char **Env)
{	
	char *pathopath;
	if (access(input[0], X_OK) == 0)
	{
		if(functionExecute(input) != 0)
			exit(EXIT_FAILURE);
		
	}

	else
	{

	}
}

/**
 *
 *
 *
 */
int functionExecute(char **input)
{	
	int status1;
	int checker = 0;
	if (fork() == 0)
	{
		checker = execve(input[0], input, NULL);
			if (checker == -1)
			{
				_printR(input[0]);
				write(STDERR_FILENO, ": No such file or direcotory\n", 28);
				exit (EXIT_FAILURE);
			}
	}

	else
	{
		wait (&status1);
	}
	
	return (0);
}
