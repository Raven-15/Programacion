#include <stdio.h>

int main() {
   int a = 0, b = 1, c = 0, sum = 0, count = 0;

   while (c <= 1000) {
      c = a + b;
      a = b;
      b = c;
      if (c <= 1000) {
         sum += c;
         count++;
      }
   }

   int average = sum / count;

   printf("El promedio entero de los elementos de la serie de Fibonacci entre 0 y 1000 es %d.\n", average);

   return 0;
}
