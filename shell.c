#include "shell.h"

/**
 * main - entry point.
 * @argv: ...
 * @argc: ..
 * Return: int
 */

int main(int argc, char *argv[])
{
	char *path, *buf;
	size_t fd;
	pid_t p_id;

	fd = STDIN_FILENO;
	buf = "($) ";
	while (1)
	{
		if (isatty(fd))
			write(1, buf, 4);

		if (argc > 1)
			return (0);

		path = _getline();
		if (path[0] ==  '\0')
		{
			free(path);
			continue;
		}

		p_id = fork();
		if (p_id == -1)
		{
			perror(argv[0]);
			free(path);
			exit(EXIT_FAILURE);
		}
		if (p_id == 0)
		{
			_execve(path, argv[0]);
		}
		wait(NULL);
		free(path);
	}
	return (0);
}
