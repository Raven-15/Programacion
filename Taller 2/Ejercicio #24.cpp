//Ejercicio #24

#include <stdio.h>

int main (){
	int n, di, suma = 0; 
	printf("Angelica digite un numero entero: ");
	scanf("%d", &n);
	
	while (n != 0) {
        di = n % 10;
        if (di % 2 == 0) {
            suma += di;
        }
        n /= 10;
    }
    printf("La suma de los digitos pares es: %d\n", n, suma);

    return 0;
}
