#include <stdio.h>
#include <stdlib.h>

int main (){
	
	float radio, area, volumen, pi=3.1416;
	
	printf("Ingrese el radio de la esfera:");
	scanf("%f",&radio);
	
	area=(4*pi)*(radio*radio);
	volumen=((4*pi)*(radio*radio*radio))/3;
	
	printf("El area de la esfera es: %f \n", area);
	printf("El volumen de la essfera es: %f \n", volumen);
	
	return 0;	
}
