#ifndef PSINFO_H_   /* Include guard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PSINFO_H_
struct InfoProccess;
typedef struct InfoProccess InfoProccess;
int showInfoProccess(char *pid, InfoProccess estructura);
void separarInfoValor(char *linea, char *info, char *valor);

#endif // FOO_H_