//Ejercicio #21

#include <stdio.h>

int main (){
	int n, suma = 0, di;
	printf("Angelica digite un numero entero: ");
	scanf("%d", &n);
	
	while (n != 0){
		di = n % 10;
		n /= 10;
		suma += di;
		
	}
	printf("La suma sus digitos es: %d\n", suma);
	
	return 0;
}
