#include "holberton.h"
/**
 * main - Driver function for UNIX interpreter
 * @argc: void
 * @argv: void
 * @env: environment
 * Return: Returns (0) if successful, otherwise accoridng error.
 */
int main(int argc, char **argv, char **env)
{
		char *src = NULL;
		char **arr = NULL;
		char **env66 = NULL;
		size_t src_size = 0;
		int check = 0;
		(void)argc;
		(void)argv;

		while (check != -1)
		{
			if (isatty(STDIN_FILENO))
				_printR("[(xshell$)] ");
			check = getline(&src, &src_size, stdin);
			src = strtok(src, "#");
			src = newLine(src);
			if (check == EOF)
			{
				_putchar('\n');
				exit(EXIT_SUCCESS);
			}
			if (check == 1)
				continue;
			arr = _tokenize(src);
			checkBuiltIn(arr, env);
			env66 = DArrDup(env);
			getDirs(arr, env66);
			free(env66);
			free(arr);
		}

	return (0);
}
/**
 *_printR - prints the string passed to it
 *
 * @str: String that is passed to print
 *
 * Return: Number of strings written to stdout
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
 *getDirs - calls the right function from i/p command
 *
 * @input: Double array of input string
 * @Env: Double array of the environment
 *
 * Return:
 */
void getDirs(char **input, char **Env)
{
	char *pathofpath;
	char *convertedInput;
	char **tokenArr;
	char **concatArg;
	char **newArg;

	if (access(input[0], X_OK) == 0)
	{
		if (functionExecute(input) != 0)
			exit(EXIT_FAILURE);
	}

	else
	{
		pathofpath = getPath(Env);
		tokenArr = tokenizePath(pathofpath);
		concatArg = command_concat(input[0], tokenArr);
		convertedInput = checkPerm(concatArg);
		newArg = argDup(input, convertedInput);

		if (functionExecute1(newArg, tokenArr, concatArg) != 0)
		{
			exit(EXIT_FAILURE);
		}
	}

}
/**
 *functionExecute - Executes the function called
 *
 *@input: Pointer to pointers to input string
 *
 * Return: 0 on success, exits on failure
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
				perror(": No such file or direcotory\n");
				exit(EXIT_FAILURE);
			}
	}

	else
	{
		wait(&status1);
				free(input);
	}
	return (0);
}
/**
 *
 *
 */

int functionExecute1(char **input, char **tokenized, char **concatedArgu)
{
	int status1;
	int checker = 0;

	if (fork() == 0)
	{
		checker = execve(input[0], input, NULL);
			if (checker == -1)
			{
				_printR(input[0]);
				write(STDERR_FILENO, ": No such file or directory\n", 28);
				exit(EXIT_FAILURE);
			}
	}

	else
	{
		wait(&status1);
			free(tokenized);
			free(concatedArgu);
			free(input);
	}
	return (0);
}
