#ifndef ERROR_H_   /* Include guard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define ERROR_H_

int validate(char **pids, int length);
void showHelp();
int isNumber();
int fountFileStatus(char *pid);

#endif // ERROR_H_    
