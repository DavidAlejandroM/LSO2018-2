#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* Escriba una función que tome un valor entero y devuelva el número con sus dígitos en reversa. Por ejemplo, dado el numero 7631, la función deberá devolver 1367.*/

int reverse(int);

int main(int argc, char *argv[]){
    int x = 0;
    char str[12];
    
    printf("Ingrese un entero X (positivo) para cerrar el programa (>1):");
    scanf("%d",&x);
    
    while(x > 0 && x != -1){
        
        int inv = reverse(x);
        
        printf("El numero invertido es:%d\n",inv);
        
        printf("Ingrese un entero X (positivo) para cerrar el programa (>1):");
        scanf("%d",&x);
        
    }
    
    return 0;
}

int reverse(int number){
    int div = number;
    int res;
    int count = 0;
    char str[12];
    char num;
    int count2 = 0;
    
    while (div > 0) {
        res = div % 10;
        div = div /10;
        num = res;
        str[count] = num;
        count++;
    }
    res = 0;

    for (int i = count-1; i >= 0; i--) {
        div = (int)str[count2];
        res += (div * pow(10, i));
        count2++;
    }
    return res;
}