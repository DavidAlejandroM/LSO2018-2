//  gcc sol_parte2_ex4.c -o sol_parte2_ex4.out
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generarNroAleatorio (int a, int b);

int main () {
  int N, M, cant, i, aleatorio;
  printf("Digite la cantidad de números que desea generar: ");
  scanf("%d",&cant);
  printf("Digite los limites (primero el superior, luego el inferior): ");
  scanf("%d%d",&N,&M);  
  srand(time(NULL)); // Inicializacion del generador
  for(i = 0; i < cant; i ++) { 
    aleatorio = generarNroAleatorio(N,M); //Genera un numero entre M y N
    printf("%d ", aleatorio);
  } 
  printf("\n");
  system("PAUSE");
  return 0;
}

int generarNroAleatorio(int a, int b){
  int n;
  n = rand()%(a-b+1)+b;
  return n;
}