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

extern char **environ;
int execute_file(char *command, char **argv);
char *tem_getline(void);
char **tmp_strtok(char *buffer);
char *getpath(char *filename);
void interacrive(void);
void _getenv(void);
void noninteractive(void);
void interactive_mode(char **argv, char **env);


#endif
