//Ejercicio #5

#include <stdio.h>

int main() {
    int numero1, numero2;

    printf("Angelica escriba dos numeros enteros: ");
    scanf("%d %d", &numero1, &numero2);

    printf("Los numeros terminados en 4 comprendidos entre %d y %d son: ", numero1, numero2);
    if (numero1 < numero2) {
        for (int i = numero1 + 1; i < numero2; i++) {
            if (i % 10 == 4) {
                printf("%d ", i);
            }
        }
    } else {
        for (int i = numero2 + 1; i < numero1; i++) {
            if (i % 10 == 4) {
                printf("%d ", i);
            }
        }
    }

    return 0;
}

