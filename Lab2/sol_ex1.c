#include <stdio.h>

/**
 *   @brief  Cuenta las veces que aparece un caracter determinado dentro de una cadena.
 *
 *   @param  array cadena de caracteres a ingresar
 *   @param  ch es el caracter a averiguar
 *   @return el numero de veces que aparece ch en array o -1 si no aparece.
 */
int contarCaracter(char *array, char ch){
  int cont = 0;
  while(*array){ 
    if(*array == ch){
      cont++;
    }
    array++;
  }   
  if(cont == 0){    
    return -1;
  }
  return cont;
}

int main(){
  int result;
  char ch;
  char array[100];
  printf("Ingrese una cadena: ");
  fgets(array, 100, stdin);
  printf("¿Cuál caracter desea contar? ");
  scanf("%c", &ch);
  result = contarCaracter(array, ch);
  if (result != -1){
    printf("El caracter '%c' está %d veces.\n", ch, result);
  }
  else{
    printf("El caracter '%c' no está.\n", ch);
  }
  return 0;
}