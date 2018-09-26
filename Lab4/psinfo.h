#ifndef PSINFO_H_   /* Include guard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PSINFO_H_

typedef struct InfoProccess{
    char name[200];
    char state[200];
    char memTotal[200];
    char memText[200];
    char memData[200];
    char memStack[200];
    char voluntario[200];
    char noVoluntario[200];
} InfoProccess;

int showInfoProccess(char *pid, FILE *inFile);
void separarInfoValor(char *linea, char *info, char *valor);

#endif // FOO_H_    