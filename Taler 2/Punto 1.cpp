#include <stdio.h>

int main(){
	float metros, pies, pulgadas;
	
	printf("Ingrese un valor en metros: ");
	scanf("%f",&metros);

    pies = metros * 3.281;
    pulgadas = metros * 39.37;
    
    printf("El valor ingresado en metros equivale a %f pies. \n ", pies);
    printf("El valor ingresado en metros equivale a %f pulgadas. \n", pulgadas);
    
    return 0;
}
