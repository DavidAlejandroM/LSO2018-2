#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct textStats{
    int nroCaracteres;
    int nroLineas;
    int nroPalabras;
    int nroEspacios;
    int nroMayusculas;
    int nroMinusculas;
    int nroDigitos;
};

int main(int argc, char *argv[]) {

    if (argc==1){
       printf("Debes ingresar mas parametros...\n");
       return 1;
    }

    char inFilename[80];
    char outFilename[80];
    strncpy(inFilename, argv[1], strlen(argv[1]) + 1);
    char *aux = malloc(sizeof(char)*80);
    for(int i = 0; i < (strlen(inFilename) - 4); i++){
        *(aux + i) = *(inFilename + i);
    }
    strcat(aux,"_stats.txt");
    strncpy(outFilename, aux, strlen(aux) + 1);

    char ch;
    FILE *inFile;
    FILE *outFile;
    inFile = fopen(inFilename,"r");
    if(inFile == NULL){
        printf("Error al abrir el archivo %s\n", inFilename);
        return -1;
    }
    do{
        ch = getc(inFile);        
        
    }while(ch != EOF);
    fclose(inFile);
    outFile = fopen(outFilename,"w");
    putc('\0',outFile);
    fclose(outFile);
    return 0;
}