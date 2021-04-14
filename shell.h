#ifndef S_SHELL
#define S_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

/**
 * struct builtins - Linked list struct type
 *
 * @nam: str malloc
 * @func: Points to next
 *
 * Description: A list containing a function and its name
 */
typedef struct builtins
{
	char *nam;
	int (*func)(char *);
} builtin_funcs;

int global_st;
char *hsh_call;
extern char **environ;

int _putchar(char c);
int invoke_sh_exit(char *cmd);
int invoke_sh_printenv(char *cmd);
int builtin_manager(char *cmd);
void hsh_error_type_a(char *cmd, int hst);
void hsh_error_type_b(char *cmd, int hst);
void error_manager(char *cmd, int hst);
int _strcmp(char *frm, const char *dst, int size);
void _atoi(int i);
void _puts(char *str);
int _puterror(char c);
int _strlen(char *s);
int check_for_empty(char *str);
char **strtok_line(char *line);
void hsh_execute(char **cmd);
#endif
