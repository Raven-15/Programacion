//Angelica
#include <stdio.h>

int main() {
    // Declaramos un vector de tamaño 5
    int numeros[5];
    
    // Asignamos valores a los elementos del vector
    numeros[0] = 05;
    numeros[1] = 10;
    numeros[2] = 15;
    numeros[3] = 20;
    numeros[4] = 25;
    
    // Imprimir los elementos del vector
    printf("El elemento del vector es: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numeros[i]);
    }
    
    return 0;
}

