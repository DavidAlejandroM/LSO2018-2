//  gcc sol_parte2_ex9.c -o sol_parte2_ex9.out
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarDigito();

int main(){
    int n1, n2, res, final = 1;
    srand(time(NULL));
    while(final != 0){
        n1 = generarDigito();
        n2 = generarDigito();
        printf("¿Cuánto es %d veces %d? ", n1, n2);
        scanf("%d", &res);
        while(res != (n1*n2)){
            printf("No. Por favor intenta nuevamente \n");
            printf("¿Cuánto es %d veces %d? ", n1, n2);
            scanf("%d", &res);
        }
        printf("Muy bien!");
        printf("\nIngrese 0 si quiere cerrar el programa: ");
        scanf("%d", &final);
    }    
    return 0;
}

int generarDigito(){
    int n;
    n = rand()%10;
    return n;
}