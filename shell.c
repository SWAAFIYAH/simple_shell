#include "shell.h"

/**
 * main - entry point.
 * @argv: ...
 * @argc: ..
 * Return: int
 */

int main(int argc, char *argv[])
{
	char  *path, **command = NULL;
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
			break;
		if (path[0] == '\0' || strcpr(path, "nil") == 1)
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
		p_id = fork();
		if (p_id == -1)
		{
			_perror(argv[0], count, command[0]);
			exit(EXIT_FAILURE);
		}
		if (p_id == 0)
		{
			_execve(command, argv[0]);
		}
		wait(NULL);
		free(path);
		free_strtok(command);
	}
	return (0);
}
