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
 * num_of_tok- execut the command
 * @str: char
 * @delim: char
 * Return: Always 0 (Success)
 */
int num_of_tok(char *str, const char *delim)
{
	int count = 0;

	char *token = str_tok(str, delim);

	if (token == NULL)
	{
		return (0);
	}

	while (token != NULL)
	{
		count++;
		token = str_tok(NULL, delim);
	}
	count++;
	return (count);
}



/**
 * loc_of_cmd- execut the command
 * @cmd: char
 * Return: Always 0 (Success)
 */
char *loc_of_cmd(char *cmd)
{
	char *path, *pathcp, *path_tok, *file_path;
	int cmd_len, path_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		pathcp = strdup(path);
		if (pathcp == NULL)
			free_str(pathcp);
		path_tok = str_tok(pathcp, ":");

		while (path_tok != NULL)
		{
			cmd_len = str_len(cmd);
			path_len = str_len(path_tok);
			file_path = malloc(sizeof(char) * (cmd_len + path_len + 2));
			if (file_path == NULL)
				free_str(file_path);
			file_path = file(file_path, cmd, path_tok);
			if (stat(file_path, &buffer) == 0)
			{
				free(pathcp);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_tok = str_tok(NULL, ":");
			}
		}
		free(pathcp);
		if (stat(cmd, &buffer) == 0)
			return (cmd);
		return (NULL);
	}
	return (NULL);
}


/**
 * file- execut the command
 * @file_path: char
 * @cmd: FILE
 * @path_tok: size_t
 * Return: Always 0 (Success)
 */
char *file(char *file_path, char *cmd, char *path_tok)
{
	file_path = strdup(path_tok);
	if (file_path == NULL)
		free_str(file_path);

	strcat(file_path, "/");
	strcat(file_path, cmd);
	strcat(file_path, "\0");

	return (file_path);
}

/**
 * exe_cmd- execut the command
 * @argv: char
 * @pro_nam: char
 * Return: Always 0 (Success)
 */

void exe_cmd(char **argv, char *pro_nam)
{
	int i;
	char *cmd, *file_path;

	for (i = 0; i < built_num(); i++)
	{
		if (strcmp(argv[0], builtin_cmd[i].name) == 0)
		{
			builtin_cmd[i].fun(argv);
			all_cmd_num++;
			return;
		}
	}

	cmd = argv[0];
	file_path = loc_of_cmd(cmd);

	all_cmd_num++;
	if (file_path == NULL)
	{
		err_msg(cmd, pro_nam);
		free(file_path);
	}
	else
	{
		fork_(file_path, argv);
	}
}