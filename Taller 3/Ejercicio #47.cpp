//Ejercicio #47

#include <stdio.h>

int main() {
	
    int n, i;
    unsigned long long factorial;
    unsigned long long sum = 0;

    printf("Angelica escriba un numero entero positivo: ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; ++i) {
        factorial = 1;

        for (int j = 1; j <= i; ++j) {
            factorial *= j;
        }

        sum += factorial;
    }

    printf("La sumatoria de los factoriales entre 1 y %d es %llu.\n", n, sum);

    return 0;
}

