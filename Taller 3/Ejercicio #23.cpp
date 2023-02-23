//Ejercicio #23

#include <stdio.h>

int main (){
	int num, suma = 0, i;
	printf("Ingrese un numero entero: ");
	scanf("%d", &num);
	
	while (num > 0){
		suma += num % 10;
		num /= 10;
	}
	for (i = 2; i < suma; i++){
		if (suma % i == 0){
     	printf("La suma sus digitos %d No es numero primo.\n", suma);
		}
	}
	return 0;
}
