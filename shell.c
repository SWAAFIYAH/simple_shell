#include "shell.h"

/**
 * main - entry point.
 * @argv: ...
 * @argc: ..
 * Return: int
 */

int main(int argc, char *argv[])
{
	char *path, **command;
	pid_t p_id, count = 0;

	while (1)
	{
		count++;
		signal(SIGINT, signal_handler);
		prompt();
		if (argc > 1)
			return (0);
		path = _getline();
		exec_built_in(path);
		if (path[0] ==  '\0' || path == NULL)
		{
			free(path);
			continue;
		}
		command = _strtok(path);
		if (command == NULL)
		{
			_perror(argv[0], count, path);
			free(path);
			continue;
		}
		free(path);
		p_id = fork();
		if (p_id == -1)
		{
			perror(argv[0]);
			free_strtok(command);
			exit(EXIT_FAILURE);
		}
		if (p_id == 0)
		{
			_execve(command, argv[0]);
		}
		wait(NULL);
		free_strtok(command);
	}
	return (0);
}
