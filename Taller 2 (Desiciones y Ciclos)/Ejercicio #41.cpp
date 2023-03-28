#include <stdio.h>

int main() {
   int a = 0, b = 1, c = 0, sum = 0;

   while (c <= 100) {
      c = a + b;
      a = b;
      b = c;
      if (c <= 100) {
         sum += c;
      }
   }

   printf("La suma de los elementos de la serie de Fibonacci entre 0 y 100 es %d.\n", sum);

   return 0;
}
