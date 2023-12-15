#include "shell.h"

/**
 * main- execut the command
 * @argc: int
 * @argv: char
 * Return: Always 0 (Success)
 */

int main(int argc, char **argv)
{
	(void)argc;

	if (isatty(STDIN_FILENO) == 1)
	{
		interactive(argv);
	}
	else
	{
		non_interactive(argv);
	}

	return (0);
}


