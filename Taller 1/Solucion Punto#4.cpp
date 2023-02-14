#include <stdio.h>
#include <stdlib.h>

int main (){
	
	float pesos, dolar, euros, trmdiad, trmdiae;
	
	printf("Ingrese la TRM del dia para dolares:");
	scanf("%f",&trmdiad);
	
	printf("Ingrese la TRM del dia para euros:");
	scanf("%f",&trmdiae);
	
	printf("Ingrese el valor en pesos:");
	scanf("%f",&pesos);
	
	dolar = pesos/trmdiad;
	euros = pesos/trmdiae;
	
	printf("El valor en dolares para los pesos ingresados equivale a: %f \n", dolar);
	printf("El valor en dolares para los pesos ingresados equivale a: %f \n", euros);
	
	return 0;	
}


