#include "shell.h"

/**
 * _execve - execute a program
 * @str: pointer to the program
 * @filename: name of the file i case of error
 * Return: nothing
 */

void _execve(char *str, char *filename)
{
	char *argv[100];

	argv[0] = str;
	argv[1] = NULL;

	if (execve(argv[0], argv, environ) == -1)
	{
		perror(filename);
		free(str);
		exit(EXIT_FAILURE);
	}
}
