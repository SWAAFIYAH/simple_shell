#include "shell.h"

/**
 * main - entry point.
 * @argv: ...
 * @argc: ..
 * Return: int
 */

int main(int argc, char *argv[])
{
	char  *path, *command[2] = {NULL, NULL}, *word;
	pid_t p_id;

	if (argc > 1)
		return (0);
	while (1)
	{
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
		word = strtok(path, " ");
		command[0] = word;
		if (word == NULL)
		{
			free(path);
			continue;
		}
		p_id = fork();
		if (p_id == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		if (p_id == 0)
		{
			_execve(command, argv[0]);
		}
		wait(NULL);
		free(path);
	}
	return (0);
}
