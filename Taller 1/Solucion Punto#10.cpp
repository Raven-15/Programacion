#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int a, b, suma, resta, mult;
	int div;
	
	printf("Ingrese 2 numeros enteros:");
	scanf("%i %i",&a, &b);
		
	suma = a+b;
	resta = a-b;
	mult = a*b;
	div = a/b;
	
	printf("SUMA: %i \n", suma);
	printf("RESTA: %i \n", resta);
	printf("MULTIPLICACION: %i \n", mult);
	printf("DIVISION: %i \n", div);
	
	return 0;	
}

