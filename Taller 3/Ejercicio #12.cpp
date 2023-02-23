//Ejercicio #12

#include <stdio.h>

int main() {
    int numero, digito, tiene_uno = 0;

    printf("Angelica ingrese un numero entero de 3 digitos: ");
    scanf("%d", &numero);

    // Obtener cada dígito utilizando la operación de módulo
    digito = numero % 10;
    if (digito == 1) {
        tiene_uno = 1;
    }
    numero /= 10;

    digito = numero % 10;
    if (digito == 1) {
        tiene_uno = 1;
    }
    numero /= 10;

    digito = numero % 10;
    if (digito == 1) {
        tiene_uno = 1;
    }

    if (tiene_uno) {
        printf("El numero ingresado si tiene el digito 1.\n");
    } else {
        printf("El numero ingresado no tiene el digito 1.\n");
    }

    return 0;
}

