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
int execute(char **tokens);
char *read_Getline(void);
char **strtok_line(char *line);
int global_st;

int _putchar(char c);
int invoke_sh_exit(char *cmd);
#endif
