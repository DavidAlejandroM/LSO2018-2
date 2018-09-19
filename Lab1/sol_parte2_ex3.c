#include <stdio.h>
#include <stdlib.h>

long factorial(long);
long elevateTo(long, int);

int main(int argc, char *argv[]){
    int x = 0;
    int numTerminos = 0;
    double sum = 1;
    int bandera = 1;
    
    printf("Ingrese el valor de X (positivo) para cerrar el programa (>1):");
    scanf("%d",&x);
    
    printf("Ingrese el numero de terminos (positivo > 0) para cerrar el programa (>1):");
    scanf("%d",&numTerminos);
    
    while(x > 0 && numTerminos > 0 && x != -1 && numTerminos != -1){
        
        for (int i = 2; i< 2*numTerminos; i=i+2) {
            long exp = elevateTo(x,i);
            long fact = factorial(i);
            if(bandera){
                sum = sum - (double)exp/fact;
                bandera = 0;
            }
            else{
                sum = sum + (double)exp/fact;
                bandera = 1;
            }
        }
        
        printf("El resultado de la suma es:%f\n",sum);
        
        printf("Ingrese el valor de X (positivo) para cerrar el programa (-1):");
        scanf("%d",&x);
        
        printf("Ingrese el valor de X (positivo) para cerrar el programa (-1):");
        scanf("%d",&numTerminos);
        
    }
    
    return 0;
}

long factorial(long x){
    long result = x;
    if(x > 1){
        result = x * factorial(x - 1);
    }
    return result;
}

long elevateTo(long base , int exp){
    long result = 1;
    for (int i=0; i< exp; i++) {
        result *= base;
    }
    if(exp==0){
        return 1;
    }
    else{
        return result;
    }
}