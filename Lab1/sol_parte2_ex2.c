//  gcc sol_parte2_ex2.c -o sol_parte2_ex2.out -lm 
#include <stdio.h>
#include <math.h>

int progresionG(int n1, int n2);

int main(){
    int x, e, result;
    printf("Ingrese el valor que tomará x: ");
    scanf("%d", &x);
    printf("Ingrese el valor del exponente: ");
    scanf("%d", &e);
    result = progresionG(x,e);
    printf("La progresión geométrica para los valores %d y %d es: %d\n", x,e,result);
}

int progresionG(int n1, int n2){
    int r = 0;
    for(int i = 0; i <= n2; i++){
        r = r + (int)pow(n1,i);
    }
    return r;
}