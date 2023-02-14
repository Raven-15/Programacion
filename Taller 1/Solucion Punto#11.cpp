#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int Y2, Y1, X2, X1, m;
	
	printf("Ingrese las coordenadas del punto en X (X2,X1):");
	scanf("%i %i",&X2, &X1);
	
	printf("Ingrese las coordenadas del punto en Y (Y2,Y1):");
	scanf("%i %i",&Y2, &Y1);
	
	m=(Y2-Y1)/(X2-X1);
	
	printf("La pendiente de la recta es: %i \n", m);
	
	return 0;	
}
