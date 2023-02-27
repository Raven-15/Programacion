//Ejercicio #13

#include <stdio.h>

int main() {
    int numero;
    printf("Angelica escriba un nnmero entero: ");
    scanf("%d", &numero);
    printf("Los múltiplos de 5 entre 1 y %d son:\n", numero);
    for (int i = 1; i <= numero; i++) {
        if (i % 5 == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}

