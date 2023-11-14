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

int execute_file(char *command, char **argv);
char *tem_getline(void);
char **tmp_strtok(char *buffer);
char *getpath(char *filename);
void interacrive();
void noninteractive();
void _getenv(void);

#endif
