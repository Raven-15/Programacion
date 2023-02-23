//Ejercicio #36

#include <stdio.h>

int main() {
    int num = 5;

    // Mostramos la tabla de multiplicar del número 5
    printf("Tabla de multiplicar del numero %d:\n", num);
    for (int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", num, i, num * i);
    }

    return 0;
}

