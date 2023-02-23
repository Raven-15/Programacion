//Ejercicio #46

#include <stdio.h>

int main() {
    int n, i, j, count = 0;
    unsigned long long factorial;
    unsigned long long sum = 0;

    printf("Angelica ingrese un numero entero positivo: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        factorial = 1;

        for (j = 1; j <= i; ++j) {
            factorial *= j;
        }

        sum += factorial;
        count++;
    }

    int average = sum / count;

    printf("El promedio entero de los factoriales entre 1 y %d es %d.\n", n, average);

    return 0;
}

