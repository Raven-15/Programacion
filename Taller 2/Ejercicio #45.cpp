//Ejercicio #45

#include <stdio.h>

int main() {
    int n, i, j;
    unsigned long long factorial;

    printf("Angelica digite un numero entero positivo: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        factorial = 1;

        for (j = 1; j <= i; ++j) {
            factorial *= j;
        }

        printf("El factorial de %d es %llu.\n", i, factorial);
    }

    return 0;
}

