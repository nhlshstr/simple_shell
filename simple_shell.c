#include "holberton.h"
void getDirs(char **input, char **Env);
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
		int check = 0;//, status;
		(void)argc;
		//int att;
		int a = 0;
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
			// move fork to function
			
			getDirs(arr, env);
			printf("This is a: %d\n", a);

			/*if (fork() == 0)
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
		}*/

		free(arr);
		return (0);
		}
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
	int checker = 0, status1;
	/*, status2,*/ 
	int compare, i;
	char *tok, *_pathString;
	if (access(input[0], X_OK) == 0)
	{
			if (fork() == 0)
			{
				checker = execve(input[0], input, NULL);
				if (checker == -1)
				{		_printR(input[0]);
						write(STDERR_FILENO, ": No such file or direcotory\n", 28);
						exit (EXIT_FAILURE);
				}
			}

			else
			{
				wait (&status1);
			}
	
	}	
}















