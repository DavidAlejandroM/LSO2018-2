#include <stdio.h>

// Codigo tomado de: https://en.wikibooks.org/wiki/C_Programming/stdio.h/getchar

 int main(void)
 {
   char str[10];
   int ch, n = 0;
   while ((ch = getchar()) != EOF && n < 10) {
      str[n] = ch;
      ++n;
   }   
   for (int i = 0; i < n; ++i)
      putchar(str[i]);

   putchar('\n');
   return 0;
 }