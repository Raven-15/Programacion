//Ejercicio #30

#include <stdio.h>

int main() {
    int numero;

    printf("Angelica ingrese un numero entero: ");
    scanf("%d", &numero);

    printf("Los componentes numericos de %d son: ", numero);

    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}

