#ifndef PSINFO_H_   /* Include guard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PSINFO_H_

typedef struct InfoProccess{
    char name[60];
    char state[60];
    char memTotal[60];
    char memText[60];
    char memData[60];
    char memStack[60];
    char voluntario[60];
    char noVoluntario[60];
} InfoProccess;

int showInfoProccess(char *pid, struct InfoProccess *estructura);
void separarInfoValor(char *linea, char *info, char *valor);

#endif // FOO_H_