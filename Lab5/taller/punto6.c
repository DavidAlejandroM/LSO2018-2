#include<stdio.h>
#include<unistd.h>
main() {
   printf("Hola ");
   fork();
   printf("Mundo");
   fork();
   printf("!");
}
