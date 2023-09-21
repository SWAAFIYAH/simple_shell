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

void signal_handler(int sig_id);
char *_getline(void);
void prompt(void);
void _perror(char *file, int number, char *command);
int _strlen(char *str);
int strcpr(char *str1, char *str2);

#endif
