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
    char ch, chAnt, chAnt2;
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
        if(ch == -1) stats->nroCaracteres--;
        //printf("%c => %d\n",ch,ch);
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
        chAnt2 = chAnt;
        chAnt = ch;
        
    }while(ch != EOF);
    printf("el numero de caracteres es %d \n", stats->nroCaracteres);
    printf("el numero de digitos es %d \n", stats->nroDigitos);
    printf("el numero de espacios es %d \n", stats->nroEspacios);
    printf("el numero de lineas es %d \n", stats->nroLineas);
    printf("el numero de mayusculas es %d \n", stats->nroMayusculas);
    printf("el numero de minusculas es %d \n", stats->nroMinusculas);
    printf("el numero de palabras es %d \n", stats->nroPalabras);
              
    fclose(inFile);
    outFile = fopen(outFilename,"w");
    putc('\0',outFile);
    fclose(outFile);
    return 0;
}