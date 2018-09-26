#include "psinfo.h"

int showInfoProccess(char *pid){
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
    char line[300];
    char info[60];
    char valor[200];
    char voluntary[200];
    while (fgets(line, 300, inFile) != NULL){
        //fgets(line,300,inFile);
        separarInfoValor(line, info, valor);
        //printf("%s  %s\n",info,valor);
        if(strcmp(info, "Name") == 0){
            printf("Nombre del proceso: %s \n",valor);
        }
        else if(strcmp(info, "State") == 0){
            printf("Estado del proceso: %s \n",valor);
        }
        else if(strcmp(info, "VmPeak") == 0){
            printf("Tamaño total de la imagen de memoria: %s \n",valor);            
        }
        else if(strcmp(info, "VmExe") == 0){
            printf("\tTamaño de la sección de memoria TEXT: %s \n",valor);            
        }
        else if(strcmp(info, "VmData") == 0){
            printf("\tTamaño de la sección de memoria DATA: %s \n",valor);            
        }
        else if(strcmp(info, "VmStk") == 0){
            printf("\tTamaño de la sección de memoria STACK: %s \n",valor);            
        }
        else if(strcmp(info, "voluntary_ctxt_switches") == 0){
            memset(voluntary, '\0', sizeof(voluntary));  
            strncpy(voluntary,valor,strlen(valor));      
        }
         else if(strcmp(info, "nonvoluntary_ctxt_switches") == 0){
            printf("Número de cambios de contexto realizados (voluntarios - no voluntarios): %s - %s\n", voluntary,valor);          
        }
        memset(info, '\0', sizeof(info));
        memset(valor, '\0', sizeof(valor));
        if(feof(inFile) == 0){
            //break;
        }
    }
    fclose(inFile);

    return 1;
}

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

