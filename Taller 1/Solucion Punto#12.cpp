#include <stdio.h>

int main() {
   float distancia, consumo, galones, precio_corriente, precio_extra, valor_corriente, valor_extra;

   printf("Ingrese la distancia a recorrer en kilómetros: ");
   scanf("%f", &distancia);

   printf("Ingrese el consumo promedio de combustible en kilómetros por galón: ");
   scanf("%f", &consumo);

   galones = distancia / consumo;

   printf("La cantidad de galones necesarios para recorrer %f kilometros es: %f\n", distancia, galones);

   printf("Ingrese el precio por galon de combustible corriente: ");
   scanf("%f", &precio_corriente);

   printf("Ingrese el precio por galon de combustible extra: ");
   scanf("%f", &precio_extra);

   valor_corriente = galones * precio_corriente;
   valor_extra = galones * precio_extra;

   printf("El valor en pesos de los galones de combustible corriente necesarios es: %f\n", valor_corriente);
   printf("El valor en pesos de los galones de combustible extra necesarios es: %f\n", valor_extra);

   return 0;
}





