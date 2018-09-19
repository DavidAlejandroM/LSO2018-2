#include <stdio.h>

double mediana(double *numeros, int size){
    double aux = 0;
    int control = 0;
    for(int i = size - 1; i >= 0 && control == 0; i--){
        control = 1;
        for(int j = 0; j < i; j++){
            if(numeros[j] > numeros[j + 1]){
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
                control = 0;
            }
        }        
    }    
    return *(numeros + (size / 2));    
}

int main(){
    int n;
    do{
        printf("Ingrese un número impar: ");
        scanf("%d", &n);
    }while(n % 2 == 0);  
     
    double numeros[n];
    for(int i = 0; i < n; i++){
        printf("Ingrese un número real: ");
        scanf("%lf", &numeros[i]);        
    }
    double m = mediana(numeros, n);
    printf("La mediana del vector es: %.2lf \n", m);
    return 0;
}