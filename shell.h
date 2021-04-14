#ifndef OWN_SHELL
#define OWN_SHELL

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

extern char **environ;
char *hsh_call;
int global_st;

void hsh_execute(char **cmd, int hst, char *);
int hsh_shell_exit(char *cmd);
int _strlen(char *s);
int hsh_shell_printenv(char *cmd);
int builtin_manager(char *cmd);
void hsh_error_type_a(char *cmd, int hst);
void hsh_error_type_b(char *cmd, int hst);
void error_manager(char *cmd, int hst);
char **hsh_shell_manage_path(char *cmd);
char **write_to_buffer(char *cmd, char *delims);
char *hsh_shell_freshpath(char *pathv);
int check_for_empty(char *env);
int _strcmp(char *frm, const char *dst, int size);
char *_getenv(char *nam);
char *_strdup(char *str);
int _putchar(char c);
int _puterror(char c);
void _puts(char *str);
char *_strcat(char *str1, char *str2);
int set_delimit(char *cmd, char *delims);
void _atoi(int i);

#endif
