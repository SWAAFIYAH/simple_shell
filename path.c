#include "shell.h"

/**
 * get_path_value - find the value of path
 * Return: return nothing
 */

char *get_path_value(void)
{
	char *word, *var, **env, *copy;
	int i;

	var = "PATH";
	i = 0;
	env = environ;

	while (env[i] != NULL)
	{
		copy = strcopy(env[i]);
		word = strtok(copy, "=");
		if (strcpr(word, var) == 1)
		{
			word = strcopy(strtok(NULL, "="));
			free(copy);
			return (word);
		}
		free(copy);
		i++;
	}
	return (NULL);
}

/**
 * check_command - ckeck if command exis
 * @str: the command
 * Return: nothing
 */

char *check_command(char *str)
{
	char *word = NULL, *path_value = NULL, *file_path = NULL;
	struct stat fs;

	if (str == NULL)
		return (NULL);

	if (stat(str, &fs) == 0)
	{
		file_path = strcopy(str);
		return (file_path);
	}

	path_value = get_path_value();
	if (path_value == NULL)
		return (NULL);

	word = strtok(path_value, ":");
	while (word != NULL)
	{
		file_path  = strconcat(word, "/", str);
		if (stat(file_path, &fs) == 0)
		{
			free(path_value);
			return (file_path);
		}
		word = strtok(NULL, ":");
		free(file_path);
	}
	free(path_value);
	return (NULL);
}
