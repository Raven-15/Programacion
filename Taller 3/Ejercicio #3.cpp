//Ejercicio #3

#include <stdio.h>

int main() {
    int numero;

    printf("Angelica escriba un numero entero: ");
    scanf("%d", &numero);

    printf("Los divisores exactos de %d son: ", numero);
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}
