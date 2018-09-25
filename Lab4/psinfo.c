#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int cont = 0;
    while (feof(inFile) == 0){
        fgets(line,100,inFile);
        cont++;
        if (cont == 1){
            printf("Nombre del proceso: %s",line);
        }
        else if(cont == 2){
            printf("Estado del proceso: %s",line);
        }  
    }
    fclose(inFile);
    return 0;
}
