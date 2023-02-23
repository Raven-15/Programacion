//Ejercicio #26

#include <stdio.h>

int main() {
    int numero;
    printf("Angelica ingrese un numero entero: ");
    scanf("%d", &numero);
    int maximo = 0;
    while (numero != 0) {
        int digito = numero % 10;
        if (digito > maximo) {
            maximo = digito;
        }
        numero = numero / 10;
    }
    printf("El mayor digito es: %d\n", maximo);
    return 0;
}

