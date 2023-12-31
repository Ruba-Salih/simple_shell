#include "shell.h"

/**
 * interactive- execut the command
 * @argv: char
 * Return: Always 0 (Success)
 */
void interactive(char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	char *pro_nam = argv[0];

	while (1)
	{
		write(1, "($) ", str_len("($) "));
		nread = get_line(&line, &len, stdin);
		if (nread != -1)
		{
			argv = tok(line, argv);
			if (argv == NULL)
			{	free(line);
				continue;
			}
			exe_cmd(argv, pro_nam);

			free(argv);
			free(line);
		}
		else
		{
			printf("\n");
			free(line);
			break;
			/*return (-1);*/
		}
	}
}



/**
 * non_interactive- execut the command
 * @argv: char
 * Return: Always 0 (Success)
 */
void non_interactive(char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	char *pro_nam = argv[0];

	while (1)
	{
		nread = get_line(&line, &len, stdin);
		if (nread != -1)
		{
			argv = tok(line, argv);
			if (argv == NULL)
			{	free(line);
				continue;
			}
			exe_cmd(argv, pro_nam);

			free(argv);
			free(line);
		}
		else
		{
			printf("\n");
			free(line);
			break;
			/*return (-1);*/
		}
	}
}

/**
 * get_line- execut the command
 * @lineptr: char
 * @stream: FILE
 * @n: size_t
 * Return: Always 0 (Success)
 */
ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	char *new_buf, *buffer;

	ssize_t size = 128;
	ssize_t char_num = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);

	buffer = malloc(sizeof(char) * size);
	if (buffer == NULL)
		free_str(buffer);

	while ((ch = fgetc(stream)) != EOF && ch != '\0')
	{
		if (ch == '\n')
			break;
		if (char_num + 1 >= size)
		{
			size *= 1;
			new_buf = realloc(buffer, size);
			if (new_buf == NULL)
				free_str(new_buf);
			buffer = new_buf;
		}
		buffer[char_num++] = ch;
	}
	if (char_num == 0 && ch == EOF)
	{
		return (-1);
	}

	buffer[char_num] = '\0';
	*lineptr = buffer;
	*n = size;
	return (char_num);
}


/**
 * if_delim- execut the command
 * @ch: char
 * @delime: char
 * Return: Always 0 (Success)
 */
int if_delim(char ch, const char *delime)
{
	while (*delime != '\0')
	{
		if (ch == *delime)
			return (1);
		delime++;
	}
	return (0);
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

