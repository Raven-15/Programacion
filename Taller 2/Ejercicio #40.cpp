#include <stdio.h>

int main() {
   int num, a = 0, b = 1, c = 0;

   printf("Ingrese un n�mero de dos d�gitos: ");
   scanf("%d", &num);

   while (c < num) {
      c = a + b;
      a = b;
      b = c;
   }

   if (c == num) {
      printf("%d pertenece a la serie de Fibonacci.\n", num);
   } else {
      printf("%d no pertenece a la serie de Fibonacci.\n", num);
   }

   return 0;
}
