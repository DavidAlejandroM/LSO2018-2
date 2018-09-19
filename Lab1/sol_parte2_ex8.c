//  gcc sol_parte2_ex8.c -o sol_parte2_ex8.out
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int lanzarMoneda();

int main(){
    int countC = 0, countS = 0, nroLanzamientos, resL;
    printf("Ingrese el número de veces que desea lanzar la moneda: ");
    scanf("%d", &nroLanzamientos);
    srand(time(NULL));
    for(int i = 1; i <= nroLanzamientos; i++){        
        resL = lanzarMoneda();
        if(resL == 0){            
            printf("C");  
            countC++;          
        }
        else{            
            printf("S");  
            countS++;
        }        
    }
    printf(", # de caras = %d, # de sellos = %d \n", countC, countS);
    return 0;
}

int lanzarMoneda(){
    int n;
    n = rand()%2;
    return n;
}