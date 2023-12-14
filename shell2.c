#include "shell.h"



/**
 * exe_cmd- execut the command
 * @argv: char
 * @pro_nam: char
 * Return: Always 0 (Success)
*/

static int all_cmd_num;
struct builtin builtin_cmd[] = {{"cd", cd_}, {"exit", exit_}, {"env", env_}};

void exe_cmd(char **argv, char *pro_nam)
{
	all_cmd_num = 0
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

/**
 * err_msg- execut the command
 * @cmd: char
 * @pro_name: char
 * Return: Always 0 (Success)
 */
void err_msg(char *cmd, char *pro_name)
{
	printf("%s: %d: %s: not found\n", pro_name, all_cmd_num, cmd);
}


/**
 * built_num- execut the command
 *
 * Return: Always 0 (Success)
 */
int built_num(void)
{
	return (sizeof(builtin_cmd) / sizeof(struct builtin));
}

/**
 * exit_- execut the command
 * @argv: char
 * Return: Always 0 (Success)
 */
void exit_(char **argv)
{
	if (argv[1] != NULL)
	{
		int status = atoi(argv[1]);

		free(argv);
		exit(status);
	}
	else
	{
		free(argv);
		exit(0);
	}
}

/**
 * env_- execut the command
 * @argv: char
 * Return: Always 0 (Success)
 */
void env_(char **argv)
{
	char **env = environ;

	(void)argv;

	while (*env != NULL)
	{
		write(1, *env, str_len(*env));
		write(1, "\n",  str_len("\n"));
		env++;
	}
}
