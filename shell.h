#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

char **tokens(char *string);
int _path(char **argv);
char *_which(char *str1, char *str2);
char *_getenv(const char *name);
#endif