#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarDigito();
int generarMsg();



int main(){
    int n1, n2, res, final = 1, contadorAciertos = 0, contadorErroneos = 0;
    char *correcto[4] = { "Muy bien!", "Excelente!", "Buen trabajo!", "Sigue haciéndolo bien!"};
    char *erroneo[4] = {"No. Por favor trata de nuevo.", "Incorrecto. Trata una vez más.", "No te rindas!", "No. Trata de nuevo"};
    srand(time(NULL));
    while(final != 0){
        n1 = generarDigito();
        n2 = generarDigito();
        printf("¿Cuánto es %d veces %d? ", n1, n2);
        scanf("%d", &res);
        while(res != (n1*n2)){
            printf("%s", erroneo[generarMsg()-1]);
            printf("\n¿Cuánto es %d veces %d? ", n1, n2);
            scanf("%d", &res);
            contadorErroneos++;
        }
        printf("%s", correcto[generarMsg()-1]);
        contadorAciertos++;
        printf("\nIngrese 0 si quiere cerrar el programa y otro número para continuar: ");
        scanf("%d", &final);
    }
    if(final == 0){
        int porcentaje = (contadorAciertos * 100) /
        (contadorAciertos+contadorErroneos);
        
        printf("Tu resultado es %d %c\n",porcentaje,37);
        if(porcentaje<75){
            printf("******* Por favor pídele ayuda al instructor *******");
        }
    }
    return 0;
}

int generarDigito(){
    int n;
    n = rand()%10;
    return n;
}

int generarMsg(){
    return rand()%(4)+1;
}
