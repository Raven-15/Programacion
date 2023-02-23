//Ejercicio #6

#include <stdio.h>

int main() {
    int numero;

    printf("Angelica  escriba un numero entero de tres digitos: ");
    scanf("%d", &numero);

    printf("Los enteros comprendidos entre 1 y cada uno de los digitos de %d son:\n", numero);
    int digito1 = numero / 100;
    int digito2 = (numero / 10) % 10;
    int digito3 = numero % 10;

    printf("Entre 1 y %d: ", digito1);
    for (int i = 1; i <= digito1; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Entre 1 y %d: ", digito2);
    for (int i = 1; i <= digito2; i++) {
        printf("%d ", i);
    }
    printf("\n");

    printf("Entre 1 y %d: ", digito3);
    for (int i = 1; i <= digito3; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}

