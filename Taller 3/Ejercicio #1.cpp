//Ejercicio #1

#include <stdio.h>
#include <string.h>

int main(){
	
	int number;
	printf("Ingrese el numero entero: \n");
	scanf("%d", &number);
	
	if(number % 2 == 0){
		printf("El numero ingresado es par");
	}else{
		printf("El numero ingresado es impar");
	}
	
	return 0;
	    
	
}
