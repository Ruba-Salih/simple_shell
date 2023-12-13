#include "shell.h"

/**
 * fork_- execut the command
 * @file_path: char
 * @argv: char
 * Return: Always 0 (Success)
 */
void fork_(char *file_path, char **argv)
{
	char **env = environ;

	pid_t chil_pid = fork();


		if (chil_pid == 0)
		{

			if (execve(file_path, argv, env) == -1)
			{

				free(argv);
				free(file_path);
				_exit(0);
			}
		}
		else if (chil_pid > 0)
		{
			int status;

			do {
				waitpid(chil_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && WIFSIGNALED(status));
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
