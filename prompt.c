#include "shell.h"

/**
 * prompt - display prompt
 * Return: nothing
 */

void prompt(void)
{
	char  *buf;
	size_t fd;

	fd = STDIN_FILENO;
	buf = ":) ";

	if (isatty(fd))
		write(1, buf, 3);
}
