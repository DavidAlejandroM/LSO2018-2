#include <stdio.h>

/**
 *   @brief  Obtiene una subcadena a tomada a partir de un subindice asociado a una subcadena
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  index indice
 *   @return un apuntador a la posicion inicial de la subcadena o NULL si el tamaño de index supera a la longitud de la cadena
 */
char *obtenerSubcadena(char *array, int index) {
    int i = 0;
    while(i <= index){
        i++;               
    }
    return array + i;
}

int main(){
    int index;
    char array[100];
    printf("Ingrese una cadena: ");
    fgets(array, 100, stdin);
    printf("Ingrese el indice para extraer una subcadena: ");
    scanf("%d", &index);
    char *subcadena = obtenerSubcadena(array, index);
    printf("La cadena ingresada fue: %s", array);
    printf("Y la subcadena es: %s \n", subcadena);
    return 0;
}