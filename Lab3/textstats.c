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

void inicializarEstadisticas(TextStats *stats){
    stats->nroCaracteres = 0;
    stats->nroDigitos = 0;
    stats->nroEspacios = 0;
    stats->nroLineas = 0;
    stats->nroMayusculas = 0;
    stats->nroMinusculas = 0;
    stats->nroPalabras = 0;
}

void calcularEstadisticas(FILE *file, TextStats *stats){
    char ch, chAnt, chAnt2;
    //char c; //variable auxiliar para contar las palabras
    do{
        ch = getc(file);  
        stats->nroCaracteres++;   
        if(ch == ' '){
            stats->nroEspacios++;
            if((chAnt >= 'A' && chAnt < 'Z') || (chAnt >= 'a' && chAnt < 'z') || (ch >= '0' && ch < '9'))
            {
                stats->nroPalabras++;
            }
        }
        else if(ch == '\n'){
            stats->nroEspacios++;
            stats->nroLineas++;
            if((chAnt2 >= 'A' && chAnt2 < 'Z') || (chAnt2 >= 'a' && chAnt2 < 'z') || (chAnt2 >= '0' && chAnt2 < '9'))
            {
                stats->nroPalabras++;
            }
        }
        else if(ch >= 'A' && ch < 'Z'){
            stats->nroMayusculas++;
        }
        else if(ch >= 'a' && ch < 'z'){
            stats->nroMinusculas++;
        } 
        else if(ch >= '0' && ch < '9'){
            stats->nroDigitos++;
        } 
        /*else if((ch == ' ' || ch == '\n'  || (ch >= ',' && ch <= '.') || (ch >= ':' && ch <= ';')) && 
                ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))){
                    stats->nroPalabras++;
        }
        c = ch;*/
        chAnt2 = chAnt;
        chAnt = ch;
    }while(ch != EOF);
}

int main(int argc, char *argv[]) {

    if (argc==1){
       printf("Debes ingresar mas parametros...\n");
       return 1;
    }

    // Inicializar los nombres de los archivos
    char inFilename[80];
    char outFilename[80];

    int varControl = 1;
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
    TextStats *stats = malloc(sizeof(TextStats));
    FILE *inFile, *outFile;
    inFile = fopen(inFilename,"r");
    // Comprobar que el archivo se ha abierto
    if(inFile == NULL){
        printf("Error al abrir el archivo %s\n", inFilename);
        return -1;
    }

    printf("Obteniendo estadisticas... \n");
    inicializarEstadisticas(stats);
    calcularEstadisticas(inFile,stats);
    fclose(inFile);
    printf("-%s --> generando reporte %s \n", inFilename, outFilename);
    
    // Escribiendo en el archivo generado
    outFile = fopen(outFilename,"w");
    fprintf(outFile, "chars: %d \n", stats->nroCaracteres);
    fprintf(outFile, "words: %d \n", stats->nroPalabras);
    fprintf(outFile, "lines: %d \n", stats->nroLineas);
    fprintf(outFile, "whitespaces: %d \n", stats->nroEspacios);    
    fprintf(outFile, "uppercase: %d \n", stats->nroMayusculas);
    fprintf(outFile, "lowercase: %d \n", stats->nroMinusculas);
    fprintf(outFile, "digits: %d \n", stats->nroDigitos);
    putc('\0',outFile);
    fclose(outFile);
    free(stats);
    printf("Estadisticas culminadas \n");
    return 0;
}