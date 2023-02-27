//Ejercicio #10

#include <stdio.h>

int main() {
    int numero, suma = 0;

    printf("Angelica escriba un numero entero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {
        suma += i;
    }

    printf("La suma de los enteros comprendidos entre 1 y %d es %d.\n", numero, suma);

    return 0;
}

