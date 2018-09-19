#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int sizeLine = 0;
    
    while(sizeLine != -1){
        printf("Ingrese el numero de lineas (positivo) para cerrar el programa (-1):");
        scanf("%d",&sizeLine);
        
        for(int i = 1; i <= sizeLine; i++)
        {
            printf("Renglon %d: ",i);
            for(int j = i; j >= 1; j--)
            {
                if(j%2 == 0){
                    printf("0");
                }
                else{
                    printf("1");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}