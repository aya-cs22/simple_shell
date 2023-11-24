#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <signal.h>

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
extern char **environ;
int execute_file(char *command, char **argv);
char *tem_getline(void);
char **tmp_strtok(char *buffer);
char *getpath(char **filename);
void interactive(void);
void _getenv(void);
void noninteractive(void);
void interactive_mode(char **argv, char **envp);


#endif
