#include "shell.h"

/**
 * _strlen - get len of string
 * @str: the string
 * Return: len of str
 */

int _strlen(char *str)
{
	int len, i;

	len = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		len += 1;
	}
	return (len);
}

/**
 * strcopy - copy string
 * @str: the string
 * Return: return the string
 */

char *strcopy(char *str)
{
	char *ptr;
	int i, len;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		ptr[i] = str[i];
	}
	return (ptr);
}

/**
 * strcpr - compire
 * @str1: string 1
 * @str2: string 2
 * Return: return  1 if same, else 0
 */

int strcpr(char *str1, char *str2)
{
	int len, i;

	len = _strlen(str1);
	for (i = 0; i <= len; i++)
	{
		if (str1[i] != str2[i])
		{
			return (0);
		}
	}
	return (1);
}

/**
 * strconcat - concatnate strings
 * @str1: string 1
 * @str2: string 2
 * @str3: string 3
 * Return: return the complite string
 */

char *strconcat(char *str1, char *str2, char *str3)
{
	char *ptr;
	int len, i, j, k;

	len = _strlen(str1) + _strlen(str2) + _strlen(str3);
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}

	for (i = 0; str1[i] != '\0'; i++)
	{
		ptr[i] = str1[i];
	}
	for (j = 0; str2[j] != '\0'; j++)
	{
		ptr[i] = str2[j];
		i++;
	}
	for (k = 0; k <= _strlen(str3); k++)
	{
		ptr[i] = str3[k];
		i++;
	}
	return (ptr);
}
