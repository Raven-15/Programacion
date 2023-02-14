#include <stdio.h>
#include <stdlib.h>

int main (){
	
	float r, area, volumen, pi=3.1416, h;
	
	printf("Ingrese el radio del cilindro:");
	scanf("%f",&r);
	
	printf("Ingrese la altura del cilindro:");
	scanf("%f",&h);
	
	area=(2*pi*r*h)+(2*pi*r*r);
	volumen=(pi*r*r*h);
	
	printf("El area del cilindro es: %f \n", area);
	printf("El volumen del cilindro es: %f \n", volumen);
	
	return 0;	
}
