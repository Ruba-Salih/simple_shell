#include "shell.h"

/**
 * cd_- execute the command
 * @argv: char
 * Return: Always 0 (Success)
 */

void cd_(char **argv)
{
	char *path = NULL;
	size_t size = 0;
	char *s = "-";

	path = getcwd(path, size);
	if (path == NULL)
		free_str(path);

	if (argv[1] == NULL)
	{
		if (chdir(getenv("HOME")) != 0)
			perror("cd");
	}
	else
	{
		if (*argv[1] == s[0])
		{
			if (chdir("..") != 0)
				perror("cd");
		}
		else if (chdir(argv[1]) != 0)
		{
			perror("cd");
		}
	}
	free(path);
}



/**
 * tok- execute the command
 * @str: char
 * @argv: char
 * Return: Always 0 (Success)
 */

char **tok(char *str, char **argv)
{
	int num_tok, i = 0;
	char *token = NULL;
	char *strcp = NULL;
	const char *delim = " \n";

	strcp = strdup(str);
	if (strcp == NULL)
		free_str(strcp);

	num_tok = num_of_tok(str, delim);
	if (num_tok == 0)
	{
		free(strcp);
		return (NULL);
	}

	argv = malloc(sizeof(char *) * num_tok);
	if (argv == NULL)
		free_strd(argv);

	token = str_tok(strcp, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * str_len(token));
		if (argv[i] == NULL)
			free_str(argv[i]);
		str_cpy(argv[i], token);
		token = str_tok(NULL, delim);
	}

	argv[i] = NULL;
	free(strcp);

	return (argv);
}

/**
 * free_str- execut the command
 * @str: char
 * Return: Always 0 (Success)
 */
void free_str(char *str)
{
	perror("malloc");
	free(str);
	exit(EXIT_FAILURE);
}


/**
 * free_strd- execut the command
 * @str: char
 * Return: Always 0 (Success)
 */
void free_strd(char **str)
{
	perror("malloc");
	free(str);
	exit(EXIT_FAILURE);
}

/**
 * str_len- execut the command
 * @str: char
 * Return: Always 0 (Success)
 */
int str_len(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}
