#include <stdio.h>

double *mediana(double *numeros, int size){
    printf("estoy dentro de la funcion");
    double aux = 0;
    int control = 0;
    for(int i = size; i > 0 && control == 0; i--){
        control = 1;
        while(*numeros){
            if(*(numeros) > *(numeros + 1)){
                aux = *(numeros);
                *(numeros) = *(numeros + 1);
                *(numeros + 1) = aux;
                control = 0;
                numeros++;
            }
        }        
    }
    for(int i = 0; i < size; i++){
        printf("El vector en la posición %d tiene %lf", i, *(numeros + i));
    }
    return (numeros + (size / 2));    
}

int main(int argc, char *argv[]){
    int n;
    do{
        printf("Ingrese un número impar: ");
        scanf("%d", &n);
    }while(n % 2 == 0);  
     
    double numeros[n];
    for(int i = 0; i < n; i++){
        printf("Ingrese un número real: ");
        scanf("%lf", numeros+i);        
    }

    for(int i = 0; i < n; i++){
        printf("El vector en la posición %d tiene %lf", i, *(numeros + i));
    }
    double *m = mediana(numeros, n);
    printf("La mediana del vector es: %lf \n", *m);
    return 0;
}
/*
 bandera=0;
    for(contador=MAX;contador>0 && bandera==0;contador--) {
        bandera=1;
        for(contador2=0;contador2<contador;contador2++) {
            if(numeros[contador2]>numeros[contador2+1]) {
                numero = numeros[contador2];
                numeros[contador2] = numeros[contador2+1];
                numeros[contador2+1]=numero;
                bandera=0;
            }
        }
    }
*/