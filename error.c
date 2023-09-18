#include "shell.h"

/**
 * _atoi - convert number to character
 * @num: the number
 * Return: nothin
 */

int _atoi(int num)
{
	char c;
	int n;

	if (num == 0)
	{
		return (0);
	}
	else
	{
		num =  num + _atoi(num / 10);
		if (num > 9)
		{
			n =  num % 10;
			c = n + '0';
			write(2, &c, 1);
		}
		else
		{
			n = num;
			c = n + '0';
			write(2, &c, 1);
		}
		return (0);
	}
}

/**
 * _perror - print error
 * @file: name of file
 * @number: error number
 * @command: wrong command
 * Return: Nothing
 */

void _perror(char *file, int number, char *command)
{
	write(2, file, _strlen(file));
	write(2, ": ", 2);
	_atoi(number);
	write(2, ": ", 2);
	write(2, command, _strlen(command));
	write(2, ": ", 2);
	write(2, "not found \n", 11);
}
