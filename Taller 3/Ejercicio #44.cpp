//Ejercicio #44

#include <stdio.h>

int main() {
	
    int n, i;
    unsigned long long factorial = 1;

    printf("Angelica dgite un numero entero positivo: ");
    scanf("%d", &n);

    for (i = 1; i <= n; ++i) {
        factorial *= i;
    }

    printf("El factorial de %d es %llu.\n", n, factorial);

    return 0;
}

