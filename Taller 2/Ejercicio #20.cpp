//Ejercicio #20

#include <stdio.h>

int main (){
	
	int n, contador;
	printf("Angelica ingrese un numero entero: ");
	scanf("%d", &n);
	
	while (n != 0){
		contador ++;
		n /= 10;
	}
	printf("El numero ingresado tiene %d digitos.", contador);
	
	return 0;

}
