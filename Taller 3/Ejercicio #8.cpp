//Ejercicio #8

#include <stdio.h>

int main() {
    printf("Los pares comprendidos entre 20 y 200 son:\n");

    for (int i = 20; i <= 200; i++) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}

