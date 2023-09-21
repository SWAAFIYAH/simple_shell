#include "shell.h"

/**
 * main - entry point.
 * @argv: ...
 * @argc: ..
 * Return: int
 */

int main(int argc, char *argv[])
{
	char  *path, *command[2];
	pid_t p_id, count = 0;

	if (argc > 1)
		return (0);
	while (1)
	{
		count++;
		signal(SIGINT, signal_handler);
		prompt();
		path = _getline();
		if  (path == NULL)
		{
			break;
		}
		command[0] = path;
		command[1] = NULL;
		p_id = fork();
		if (p_id == -1)
		{
			_perror(argv[0], count, path);
			exit(EXIT_FAILURE);
		}
		if (p_id == 0)
		{
			if (execve(command[0], command, environ) == -1)
			{
				_perror(argv[0], count, path);
				exit(EXIT_FAILURE);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
			free(path);
		}
	}
	return (0);
}
