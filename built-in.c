#include "shell.h"

/**
 * exec_built_in - execute built_in command
 * @str: command
 * Return: Nothing
 */

void exec_built_in(char *str)
{
	char **env;
	int i;

	if (strcpr(str, "exit") == 1)
	{
		free(str);
		_exit(1);
	}
	if (strcpr(str, "env") == 1)
	{
		env = environ;
		i = 0;

		while (env[i] != NULL)
		{
			write(1, env[i], _strlen(env[i]) + 1);
			write(1, "\n", 2);
			i++;
		}
	}
}
