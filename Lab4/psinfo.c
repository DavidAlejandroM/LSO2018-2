#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(int argc, char *argv[]){
    // Comprobar que se haya ingresado el parámetro (PID)
    if (argc==1){
       printf("Debes ingresar mas parametros...\n");
       return 1;
    }
    // Inicialización de variables
    char pid[10];
    strncpy(pid, argv[1], strlen(argv[1]) + 1);
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
    while (feof(inFile) == 0){
        fgets(line,100,inFile);
        separarInfoValor(line, info, valor);    
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
            strncpy(voluntary,valor,strlen(valor));       
        }
        else if(strcmp(info, "nonvoluntary_ctxt_switches") == 0){
            printf("Número de cambios de contexto realizados (voluntarios - no voluntarios): %s - %s\n", voluntary,valor);            
        }
        memset(info, '\0', sizeof(info));
        memset(valor, '\0', sizeof(valor));           
    }
    fclose(inFile);
    return 0;
}
