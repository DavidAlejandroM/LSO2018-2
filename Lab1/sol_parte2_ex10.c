//  gcc sol_parte2_ex10.c -o sol_parte2_ex10.out
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
             switch(rand()%4){
                case 0:
                    printf("No. Por favor trata de nuevo.");
                    break;
                case 1:
                    printf("Incorrecto. Trata una vez más.");
                    break;

                case 2:
                    printf("No te rindas!");
                    break;
                case 3:
                    printf("No. Trata de nuevo");
                    break;
            }           
            printf("\n¿Cuánto es %d veces %d? ", n1, n2);
            scanf("%d", &res);
        }
        switch(rand()%4){
            case 0:
                printf("Muy bien!");
                break;
            case 1:
                printf("Excelente!");
                break;

            case 2:
                printf("Buen trabajo!");
                break;
            case 3:
                printf("Sigue haciéndolo bien!");
                break;
        }
        printf("%s", correcto[generarMsg()-1]);
        printf("\nIngrese 0 si quiere cerrar el programa y otro número para continuar: ");
        scanf("%d", &final);
    }    
    return 0;
}

int generarDigito(){
    int n;
    n = rand()%10;
    return n;
}