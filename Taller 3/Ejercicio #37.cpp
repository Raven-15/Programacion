//Ejercicio #37

#include <stdio.h>

int main() {
	
    // se muestra todas las tablas de multiplicar del 1 al 10
    for (int i = 1; i <= 10; i++) {
        printf("Angelica escriba la tabla de multiplicar del n�mero %d:\n", i);
        for (int j = 1; j <= 10; j++) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n"); // se a�ade una l�nea en blanco despu�s de cada tabla
    }

    return 0;
}

