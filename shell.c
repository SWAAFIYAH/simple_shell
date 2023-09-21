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
		if (path[0] == '\0')
		{
			free(path);
			continue;
		}
		word = strtok(path, " ");
		command[0] = word;
		p_id = fork();
		if (p_id == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		if (p_id == 0)
		{
			if (execve(command[0], command, environ) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
			free(path);
		}
	}
	return (0);
}
