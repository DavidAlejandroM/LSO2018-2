#ifndef REPORT_H_   /* Include guard */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "psinfo.h"

#define REPORT_H_

void generateReport(char *fileName, InfoProccess *infoProccess, char *pid);
void getReportFileName(char **pids, int length,char *output);

#endif // FOO_H_    
