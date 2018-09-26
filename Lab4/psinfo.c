#include "psinfo.h"
#include "report.h"

void separarInfoValor(char *linea, char *info, char *valor){
    int i = 0, j = 0;
    do{
        *(info + i) = *(linea + i);
        i++;
    }while(*(linea + i) != 58);
    *(info + i) = 0;
    i++;
    do{
        *(valor + j) = *(linea + i);
        i++;
        j++;
    }while(*(linea + i) != 0);
    *(valor + j) = 0;
}

int showInfoProccess(char *pid, FILE *inFile, int type, char *filename){
      // Inicio de la lectura del archivo
    InfoProccess *infoP = malloc(sizeof(InfoProccess));
    char *line = malloc(sizeof(char)*100);
    char *info = malloc(sizeof(char)*60);
    char *valor = malloc(sizeof(char)*200);
    while (fgets(line,300,inFile) != NULL){
        separarInfoValor(line, info, valor); 
        if(strcmp(info, "Name") == 0){
            strncpy(infoP->name,valor,strlen(valor) + 1);
        }
        else if(strcmp(info, "State") == 0){
            strncpy(infoP->state,valor,strlen(valor) + 1);
        }
        else if(strcmp(info, "VmPeak") == 0){
            strncpy(infoP->memTotal,valor,strlen(valor) + 1);          
        }
        else if(strcmp(info, "VmExe") == 0){
            strncpy(infoP->memText,valor,strlen(valor) + 1);           
        }
        else if(strcmp(info, "VmData") == 0){
            strncpy(infoP->memData,valor,strlen(valor) + 1);            
        }
        else if(strcmp(info, "VmStk") == 0){
           strncpy(infoP->memStack,valor,strlen(valor) + 1);           
        }
        else if(strcmp(info, "voluntary_ctxt_switches") == 0){
            strncpy(infoP->voluntario,valor,strlen(valor) + 1);       
        }
        else if(strcmp(info, "nonvoluntary_ctxt_switches") == 0){
            strncpy(infoP->noVoluntario,valor,strlen(valor) + 1);            
        }
        memset(info, '\0', sizeof(info));
        memset(valor, '\0', sizeof(valor));       
    }
	if(type == 1){
    printf("Pid: %s\n",pid);
    printf("Nombre de proceso: %s\n",infoP->name);
    printf("Estado: %s\n",infoP->state); 
    printf("Tamaño total de la imagen de memoria: %s\n",infoP->memTotal);
    printf("\tTamaño de la memoria en la región TEXT: %s\n",infoP->memText);
    printf("\tTamaño de la memoria en la región DATA: %s\n",infoP->memData);
    printf("\tTamaño de la memoria en la región STACK: %s\n",infoP->memStack);
    printf("Número de cambios de contexto realizados (voluntarios - no voluntarios): %s - %s\n",infoP->voluntario,infoP->noVoluntario);
	}
	else if(type == 2){
		generateReport(filename,infoP,pid);
	}
    infoP = NULL;
    free(infoP);
    line = NULL;
    free(line);
    info = NULL;
    free(info);
    valor = NULL;
    free(valor);
}
