//Ejercicio #23

#include <stdio.h>

int main (){
	int n, suma = 0, i;
	printf("Ingrese un numero entero: ");
	scanf("%d", &n);
	
	while (n > 0){
		suma += n % 10;
		n /= 10;
	}
	for (i = 2; i < suma; i++){
		if (suma % i == 0){
     	printf("La suma sus digitos %d No es numero primo.\n", suma);
		}
	}
	return 0;
}
