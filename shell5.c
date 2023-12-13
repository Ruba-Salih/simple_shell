#include "shell.h"

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
