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
		char **env66 = NULL;
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
 *newLine - converts encountered new line into NULL byte
 *
 * @src: String that is passed
 *
 * Return: String with null termination 
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
		if(functionExecute(input) != 0)
			exit(EXIT_FAILURE);
		
	}

	else
	{
		pathofpath = getPath(Env);	
		tokenArr = tokenizePath(pathofpath);//MUST FREE DOUBLE ARRAY RETURNED
		concatArg = command_concat(input[0], tokenArr);//MUST FREE DOUBLE ARRAY RETURNED
		convertedInput = checkPerm(concatArg);
		newArg = argDup(input, convertedInput);//MUST FREE DA RETURNED
	
		if(functionExecute1(newArg, tokenArr, concatArg, newArg) != 0)
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
/**
 *
 *
 */

int functionExecute1(char **input, char **tokenized, char **concatedArgu, char **newestArg)
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
		free (tokenized);
		free (concatedArgu);
		free (newestArg);
	}
	
	return (0);
}
/**
 *getPath - function to get the path of PATH
 *
 * @envi: Pointer to environment variables
 *
 *Return: Path of path on success (Always success as PATH always exists)
 */
char *getPath(char **envi)
{
		int i, compcheck = 0;
		for (i = 0; envi[i] != NULL; i++)
		{
				compcheck = _strcmp("PATH", strtok(envi[i], "="));
				if (compcheck == 0)
				{
						break;
				}
		}

		return (strtok(NULL, "\0"));
}
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
/**
 *
 *
 *
 */
char **command_concat(char *string1, char **dblArr)
{
	char **concatDArray;
	char **slashPath;
	char *temp;
	char *temp2;
	int i = 0, count = 0, j = 0;
	for(i = 0; dblArr[i] != NULL; i++)
	{	
		count++;
	}

	slashPath = malloc(sizeof(char*) * (count + 1));
	for (i = 0; dblArr[i] != NULL; i++)
	{
			temp2 = strdup(dblArr[i]);
			slashPath[i] = _strcat(temp2, "/");
	}

	concatDArray = malloc(sizeof(char *) * (count + 1));
	for(j = 0; dblArr[j] != NULL; j++)
	{	
		temp = _strdup(slashPath[j]);
		concatDArray[j] = _strcat(temp, string1);
		
	}
	concatDArray[count] = NULL;
	
	return(concatDArray);
}
/**
 *checkPerm - check's the existence of a file
 *
 *@dirsWithSlash: Pointers to strings of directory with appropriate slashes
 *
 * Return: Integer to indicate success or failure
 */
char *checkPerm(char **dirsWithSlash)
{	
	int i = 0;
	struct stat *buf; 
	buf = malloc (sizeof(struct stat));
	while (dirsWithSlash[i] != NULL)
	{
			if(stat(dirsWithSlash[i], buf) == 0)
			{
				if (access(dirsWithSlash[i], X_OK) == 0)
				{
					return (dirsWithSlash[i]);
			
				}
			}
			i++;
	}
	return(dirsWithSlash[i]);
}
/**
 *
 *
 *
 */
char **argDup(char **ip, char *newArg)
{
	char **manipString;
	int i, count = 0; 
	
	for (i = 0; ip[i] != NULL; i++)
	{
			count++;
	}

	manipString = malloc(sizeof(char*) * (count + 1));
	manipString[0] = newArg;
	for (i = 1; ip[i] != NULL; i++)
	{
		manipString[i] = ip[i];
	}

	manipString[count] = NULL;

	return (manipString);
}
/**
 *
 *
 *
 */
char **DArrDup(char **src)
{
		int i, count = 0;
		char **dest;
		for (i = 0; src[i] != NULL; i++)
		{
			count++;
		}
		dest = malloc(sizeof(char *) * (count + 1));
		for (i = 0; src[i] != NULL; i++)
		{
				dest[i] = _strdup(src[i]);
		}
		dest[count] = NULL;

		return (dest);
}




















