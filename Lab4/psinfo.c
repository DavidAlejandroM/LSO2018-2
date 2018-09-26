#include "psinfo.h"



void separarInfoValor(char *linea, char *info, char *valor){
    int i = 0, j = 0;
    do{
        *(info + i) = *(linea + i);
        i++;
    }while(*(linea + i) != ':');
    i++;
    do{
        *(valor + j) = *(linea + i);
        i++;
        j++;
    }while(*(linea + i) != '\n');
}

int showInfoProccess(char *pid,struct InfoProccess *estructura){
      // Inicio de la lectura del archivo
    InfoProccess *infoP = malloc(sizeof(InfoProccess));
    char *line = malloc(sizeof(char)*100);
    char *info = malloc(sizeof(char)*40);
    char *valor = malloc(sizeof(char)*60);
    while (fgets(line,100,inFile) != NULL){
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
    fclose(inFile);
    printf("Pid: %s\nNombre de proceso: %s\nEstado: %s\nTamaño total de la imagen de memoria: %s\n
                \tTamaño de la memoria en la región TEXT: %s\n\tTamaño de la memoria en la región DATA: %s\n
                \tTamaño de la memoria en la región STACK: %s\n
                Número de cambios de contexto realizados (voluntarios - no voluntarios): %s - %s\n",
                pid,infoP->name,infoP->state,infoP->memTotal,infoP->memText,infoP->memData,
                infoP->memStack,infoP->voluntario,infoP->noVoluntario);
    free(infoP);
    free(line);
    free(info);
    free(valor);
}