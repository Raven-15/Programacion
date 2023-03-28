//Ejercicio #29

#include <stdio.h>

int main() {
    int numero, primer_digito;
    printf("Angelica digite un numero entero: ");
    scanf("%d", &numero);

    while (numero >= 10) {
        numero /= 10;
    }
    primer_digito = numero;

    printf("El primer digito del numero es %d\n", primer_digito);

    return 0;
}

