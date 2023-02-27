#include <stdio.h>

int main() {
   int x1, y1, x2, y2;
   float pendiente;

   printf("Ingrese las coordenadas del primer punto (x1, y1): ");
   scanf("%d %d", &x1, &y1);

   printf("Ingrese las coordenadas del segundo punto (x2, y2): ");
   scanf("%d %d", &x2, &y2);

   pendiente = (float)(y2 - y1) / (float)(x2 - x1);

   printf("La pendiente de la recta que pasa por los puntos (%d, %d) y (%d, %d) es: %f\n", x1, y1, x2, y2, pendiente);

   return 0;
}
