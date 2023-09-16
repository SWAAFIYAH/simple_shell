#include "shell.h"

/**
 * exit_shell - exit the shell
 * @str: command
 * Return: Nothing
 */

void exit_shell(char *str)
{
	if (strcpr(str, "exit") == 1)
	{
		free(str);
		_exit(1);
	}
}
