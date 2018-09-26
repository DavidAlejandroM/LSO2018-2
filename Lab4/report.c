#include "report.h"


int flagIO1 = 0;

void generateReport(char *fileName, InfoProccess *infoProccess, char *pid){
	FILE *fp;
	if(flagIO1 == 0){
		fp = fopen(fileName, "w+");
		fputc(0,fp);
		flagIO1 = 1;
		fclose(fp);
	}

	fp = fopen(fileName, "a");
	fprintf(fp, "Pid: %s\n",pid);
    fprintf(fp, "Nombre de proceso: %s\n",infoProccess->name);
    fprintf(fp, "Estado: %s\n",infoProccess->state); 
    fprintf(fp, "Tamaño total de la imagen de memoria: %s\n",infoProccess->memTotal);
    fprintf(fp, "\tTamaño de la memoria en la región TEXT: %s\n",infoProccess->memText);
    fprintf(fp, "\tTamaño de la memoria en la región DATA: %s\n",infoProccess->memData);
    fprintf(fp, "\tTamaño de la memoria en la región STACK: %s\n",infoProccess->memStack);
    fprintf(fp, "Número de cambios de contexto realizados (voluntarios - no voluntarios): %s - %s\n",infoProccess->voluntario,infoProccess->noVoluntario);
	fclose(fp);
}

void getReportFileName(char **pids, int length,char *output){
	char nameFile[100] = "psinfo-report-";
    for(int i = 2; i < length; i++){
		char pid[10];
        strncpy(pid, pids[i], strlen(pids[i]));
		strcat(nameFile,pid);
		if(i != length-1){
			strcat(nameFile,"-");
		}
	}
	strcat(nameFile,".info");
	strcpy(output,nameFile);
}


