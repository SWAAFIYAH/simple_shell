#include "shell.h"

/**
 * _getline - get data from stdin
 * Return: returns the data
 */

char *_getline()
{
	char *buf = NULL;
	size_t size = 0;
	ssize_t  line = 0;

	line = getline(&buf, &size, stdin);
	if (line == -1)
	{
		free(buf);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		return (NULL);
	}
	if (line == 0)
	{
		return ("nil");
	}

	if (line > 0 && buf[line - 1] == '\n')
		buf[line - 1] = '\0';

	return (buf);
}
