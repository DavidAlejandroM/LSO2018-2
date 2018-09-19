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
    strncpy(outFilename, argv[1], strlen(argv[1]) + 1);

    char ch;
    FILE *inFile;
    FILE *outFile;
    strcat(outFilename,"_stats.txt");
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