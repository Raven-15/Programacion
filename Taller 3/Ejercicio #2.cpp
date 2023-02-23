//Ejercicio #2

#include <stdio.h>

int main() {
    int numero;

    printf("Angelica escriba un numero entero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }

    return 0;
}




