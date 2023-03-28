#include <stdio.h>

int main() {
   int n, i;
   printf("Ingrese la cantidad de términos que desea imprimir: ");
   scanf("%d", &n);
   
   int fib[n];
   fib[0] = 0; 
   fib[1] = 1; 
   

   for (i = 2; i < n; i++) {
      fib[i] = fib[i-1] + fib[i-2];
   }
   
   
   printf("La serie de Fibonacci con %d términos es: ", n);
   for (i = 0; i < n; i++) {
      printf("%d ", fib[i]);
   }
   printf("\n");
   
   return 0;
}
