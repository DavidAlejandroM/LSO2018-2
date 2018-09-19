#include <stdio.h>
#include <stdlib.h>

int esMultiplo(int , int);

int main(int argc, char *argv[]){
    int valor1, valor2 = 0;
    
    printf("Ingrese valor 1: ");
    scanf("%d",&valor1);
    
    printf("\nIngrese valor 2: ");
    scanf("%d",&valor2);

    if(esMultiplo(valor1, valor2)){
        printf("\n%d es multiplo de %d\n",valor2,valor1);
    }
    else{
        printf("\n%d NO es multiplo %d\n",valor2,valor1);
    }
    return 0;
}

/*
 *  esMultiplo: esta funcion recibe dos enteros y valida si valor2
 *  es multiplo de valor1, si es así retorna un 1 de lo contrario
 *  retorna un 0
 */
int esMultiplo(int valor1, int valor2){
    if(valor2%valor1 == 0){
        return 1;
    }
    else{
        return 0;
    }
}