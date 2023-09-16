#include "shell.h"

/**
 * _execve - execute a program
 * @str: pointer to the program
 * @filename: name of the file i case of error
 * Return: nothing
 */
void _execve(char **str, char *filename)
{
	if (execve(str[0], str, environ) == -1)
	{
		perror(filename);
		free_strtok(str);
		exit(EXIT_FAILURE);
	}
}
