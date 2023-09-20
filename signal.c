#include "shell.h"

/**
  * signal_handler - Handles the signals
  * @sig_id: The signal id
  *
  * Return: Nothing
  */

void signal_handler(int sig_id)
{
	if (sig_id == SIGINT)
		write(STDOUT_FILENO, "\n($)", 4);
}
