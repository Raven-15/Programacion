#include <stdio.h>

int main() {
   float base, altura, area;

   printf("Ingrese la base del tri�ngulo: ");
   scanf("%f", &base);

   printf("Ingrese la altura del tri�ngulo: ");
   scanf("%f", &altura);

   area = (base * altura) / 2;

   printf("El �rea del tri�ngulo es: %f\n", area);

   return 0;
}
