#include "psinfo.h"

struct InfoProccess{
    char name[60];
    char state[60];
    char memTotal[60];
    char memText[60];
    char memData[60];
    char memStack[60];
    char voluntario[60];
    char noVoluntario[60];
};

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

int showInfoProccess(char *pid, InfoProccess estructura){
    // Inicialización de variables
    char ruta[80] = "/proc/";
    strcat(ruta,pid);
    strcat(ruta,"/status");
    FILE *inFile;
    inFile = fopen(ruta,"r");
    // Comprobar que el archivo se ha abierto
    if(inFile == NULL){
        printf("Error al abrir el archivo %s\n",ruta);
        return -1;
    }
    // Inicio de la lectura del archivo
    char line[100];
    char info[40];
    char valor[60];
    char voluntary[60];
    while (fgets(line,100,inFile) != NULL){
        separarInfoValor(line, info, valor); 
        if(strcmp(info, "Name") == 0){
            strncpy(estructura->name,valor,strlen(valor) + 1);
        }
        else if(strcmp(info, "State") == 0){
            strncpy(estructura->state,valor,strlen(valor) + 1);
        }
        else if(strcmp(info, "VmPeak") == 0){
            strncpy(estructura->memTotal,valor,strlen(valor) + 1);          
        }
        else if(strcmp(info, "VmExe") == 0){
            strncpy(estructura->memText,valor,strlen(valor) + 1);           
        }
        else if(strcmp(info, "VmData") == 0){
            strncpy(estructura->memData,valor,strlen(valor) + 1);            
        }
        else if(strcmp(info, "VmStk") == 0){
           strncpy(estructura->memStack,valor,strlen(valor) + 1);           
        }
        else if(strcmp(info, "voluntary_ctxt_switches") == 0){
            strncpy(estructura->voluntario,valor,strlen(valor) + 1);       
        }
        else if(strcmp(info, "nonvoluntary_ctxt_switches") == 0){
            strncpy(estructura->noVoluntario,valor,strlen(valor) + 1);            
        }
        memset(info, '\0', sizeof(info));
        memset(valor, '\0', sizeof(valor));       
    }
    fclose(inFile);
    return 0;
}