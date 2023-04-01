//Angelica Punto #4

#include <stdio.h>

#define TAMANO_VECTOR 100

int main() {
    int numeros[TAMANO_VECTOR];
    int i;

    // escribir los 100 primeros números enteros
    for (i = 0; i < TAMANO_VECTOR; i++) {
        numeros[i] = i+1;
    }

    // contenido del vector en orden descendente
    printf("Contenido del vector en orden descendente:\n");
    for (i = TAMANO_VECTOR-1; i >= 0; i--) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}

