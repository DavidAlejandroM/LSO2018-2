#include <stdio.h>
#include <stdlib.h>

int main(){
    double result = 0;
    double valIn = 0;
    
    while(valIn != -1){
        printf("ingrese el valor de la comision. (Para finalizar ingresar -1):");
        scanf("%lf", &valIn);
        
        if(valIn >= 0 && valIn <= 20000){
            result = valIn * 1.05;
        }
        else if(valIn >= 20001 && valIn <= 50000){
            result =  (valIn - 20000) * 0.07 + 1000;
        }
        else if(valIn > 50000){
            result =  (valIn - 50000 * 0.1) + 3100;
        }
        else{
            printf("el valor es erroneo\n");
            return 0;
        }
        
        printf("el valor total de la comision es: %.0lf\n\n\n", result);
    }
    
    return 0;
}