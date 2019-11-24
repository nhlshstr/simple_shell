#include "holberton.h"
int main(int argc, char **argv, char** envp)
{
	char* copy_env;
	int i = 0;
	(void)argc;
	(void)argv;

	for(; envp[i] != NULL; i++)
	{
		copy_env = envp[i];
		printf("%s\n", copy_env);
	}
	return 0;
}
