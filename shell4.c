#include "shell.h"

/**
 * str_tok- execut the command
 * @str: char
 * @delime: char
 * Return: Always 0 (Success)
 */
char *str_tok(char *str, const char *delime)
{
	static char *tok;
	char *strcp;

	if (!str)
		str = tok;
	if (!str)
		return (NULL);

	while (1)
	{
		if (if_delim(*str, delime))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}

	strcp = str;
	while (1)
	{
		if (*str == '\0')
		{
			tok = str;
			return (strcp);
		}
		if (if_delim(*str, delime))
		{
			*str = '\0';
			tok = str + 1;
			return (strcp);
		}
		str++;
	}
}

/**
 * str_cpy- execut the command
 * @dest: char
 * @src: char
 * Return: Always 0 (Success)
 */
char *str_cpy(char *dest, const char *src)
	{
		char *tmp = dest;

		while (*dest)
			dest++;

		while (*src)
		{
			*dest++ = *src++;
		}
		*dest = '\0';
		return (tmp);
	}
