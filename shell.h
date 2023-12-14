#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

void interactive(char **argv);
void non_interactive(char **argv);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);
char *str_tok(char *str, const char *delime);
char **tok(char *str, char **argv);
void exe_cmd(char **argv, char *pro_nam);
void fork_(char *file_path, char **argv);
char *loc_of_cmd(char *cmd);
int num_of_tok(char *str, const char *delim);
char *file(char *file_path, char *cmd, char *path_tok);
void free_str(char *str);
void free_strd(char **str);
int str_len(const char *str);
char *str_cpy(char *dest, const char *src);
int if_delim(char ch, const char *delime);
void err_msg(char *cmd, char *pro_name);
void cd_(char **argv);
void exit_(char **argv);
void env_(char **argv);
int built_num(void);



extern char **environ;
/**
 * struct builtin - Short description
 * @name: First member
 * @fun: First member
 * Description: Longer description
 */
struct builtin
{
	char *name;
	void (*fun)(char **argv);
};

#endif
