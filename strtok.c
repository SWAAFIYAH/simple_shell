#include "shell.h"

/**
 * free_strtok - frees strtok
 * @str: pointer to strtok
 * Return: nothing
 */

void free_strtok(char **str)
{
	char **tmp = str;

	if (str)
	{
		while (*str)
		{
			free(*str++);
		}
		free(tmp);
	}
}

/**
 * _strtok - create string toking
 * @str: the string
 * Return: array of pointers to the strings
 */

char **_strtok(char *str)
{
	char *word = NULL, **ptr = NULL, *copy = NULL;
	int i, len = 0;

	if (str == NULL)
		return (NULL);
	copy = strcopy(str);
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == ' ')
		{
			len++;
		}
	}
	ptr = malloc(sizeof(char *) * (len + 2));
	if (ptr == NULL)
	{
		free(copy);
		return (NULL);
	}
	i = 0;
	word = strtok(copy, " ");
	while (i <= len)
	{
		ptr[i] = strcopy(word);
		word = strtok(NULL, " ");
		i++;
	}
	ptr[i] = NULL;
	free(copy);
	return(ptr);
}
