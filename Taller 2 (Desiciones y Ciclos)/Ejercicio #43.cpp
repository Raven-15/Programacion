#include <stdio.h>

int main() {
   int a = 0, b = 1, c = 0, count = 0;

   // generar los términos de la serie hasta llegar a 2000
   while (c <= 2000) {
      c = a + b;
      a = b;
      b = c;
      if (c >= 1000 && c <= 2000) {
         count++;
      }
   }

   printf("Hay %d elementos de la serie de Fibonacci entre 1000 y 2000.\n", count);

   return 0;
}
