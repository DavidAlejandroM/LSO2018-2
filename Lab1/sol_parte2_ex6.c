//  gcc sol_parte2_ex6.c -o sol_parte2_ex6.out -lm 
#include <stdio.h>
#include <math.h>

int discriminante(int a, int b, int c);

int main(){
    int a, b, c, d;
    printf("Ingrese los valores para a, b y c: ");
    scanf("%d %d %d", &a, &b, &c);
    d = discriminante(a, b, c);
    if(d == 0){
        printf("La ecuación cuadrática tiene dos raíces reales iguales \n");
    }
    else if(d == -1){
        printf("La ecuación cuadrática tiene como solución dos raíces complejas conjugadas \n");
    }
    else{
        printf("La ecuación cuadrática tiene como solución dos raíces reales y distintas \n");
    }
    return 0;
}

int discriminante(int a, int b, int c){
    int d;
    d = (int)pow(b,2) - 4*a*c;
    if(d < 0){
        return -1;
    }
    else if(d == 0){
        return 0;
    }
    else{
        return 1;
    }
}