#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

extern char **environ;

char *check_command(char *str);
char *get_path_value(void);
void signal_handler(int sig_id);
void _execve(char **str, char *filename);
char *_getline(void);
void prompt(void);
char *strconcat(char *str1, char *str2, char *str3);
char *strcopy(char *str);
int _strlen(char *str);
int strcpr(char *str1, char *str2);
void free_strtok(char **str);
char **_strtok(char *str);

#endif
