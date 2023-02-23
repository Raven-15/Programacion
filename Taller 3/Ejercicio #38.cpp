//Ejercicio #38

#include <stdio.h>

int main() {
    int numero, resultado;
    printf("Angelica escriba un numero entero: ");
    scanf("%d", &numero);
    printf("Tabla de multiplicar del %d:\n", numero);
    for(int i = 1; i <= 10; i++) {
        resultado = numero * i;
        printf("%d x %d = %d\n", numero, i, resultado);
    }
    return 0;
}

