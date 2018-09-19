#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TextStats{
    int nroCaracteres;
    int nroLineas;
    int nroPalabras;
    int nroEspacios;
    int nroMayusculas;
    int nroMinusculas;
    int nroDigitos;
} TextStats;

int main(int argc, char *argv[]) {

    if (argc==1){
       printf("Debes ingresar mas parametros...\n");
       return 1;
    }

    // Inicializar los nombres de los archivos
    char inFilename[80];
    char outFilename[80];
    strncpy(inFilename, argv[1], strlen(argv[1]) + 1);
    
    // Se implementa para generar el nombre del archivo con estadisticas, eliminando el .txt del nombre del archivo original
    char *aux = malloc(sizeof(char)*80);
    for(int i = 0; i < (strlen(inFilename) - 4); i++){
        *(aux + i) = *(inFilename + i);
    }
    strcat(aux,"_stats.txt");
    strncpy(outFilename, aux, strlen(aux) + 1);
    free(aux);

    // Creación de variables y apuntadores para el manejo de los archivos
    char ch;
    TextStats *stats = malloc(sizeof(TextStats));
    FILE *inFile, *outFile;
    inFile = fopen(inFilename,"r");
    // Comprobar que el archivo se ha abierto
    if(inFile == NULL){
        printf("Error al abrir el archivo %s\n", inFilename);
        return -1;
    }
    
    stats->nroCaracteres = 0;
    stats->nroDigitos = 0;
    stats->nroEspacios = 0;
    stats->nroLineas = 0;
    stats->nroMayusculas = 0;
    stats->nroMinusculas = 0;
    stats->nroPalabras = 0;

    do{
        ch = getc(inFile);  
        stats->nroCaracteres ++;         
        
    }while(ch != EOF);
    //printf("el numero de caracteres es %d \n", stats->nroCaracteres);     
    fclose(inFile);
    outFile = fopen(outFilename,"w");
    putc('\0',outFile);
    fclose(outFile);
    return 0;
}