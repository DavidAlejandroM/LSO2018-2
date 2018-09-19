//  gcc sol_parte1_ex2.c -o sol_parte1_ex2.out
#include <stdio.h>

int main() {
  int n,r;
  printf("Digite el número final: ");
  scanf("%d", &n);
  printf("Tablas de multiplicación desde 1 hasta %d: \n",n);
  for(int i = 1; i <= 10; i++){
      for(int j = 1; j <= n; j++){
          r = j * i;
          printf("%dx%d = %d \t", j, i, r);
      }
      printf("\n");      
  }
  return 0;
}