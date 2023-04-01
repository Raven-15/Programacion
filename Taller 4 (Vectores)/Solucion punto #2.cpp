//Angelica Punto #2

#include <stdio.h>

#define MAX_N 50

int main() {
    int n;
    int vectorA[MAX_N], vectorB[MAX_N], resultado[MAX_N];

    // Ingresar el tamaño de los vectores
    printf("Ingrese los vectores (maximo %d): ", MAX_N);
    scanf("%d", &n);

    // Ingresar los elementos del primer vector
    printf("Ingrese los elementos del primer vector:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i+1);
        scanf("%d", &vectorA[i]);
    }

    // Ingresar los elementos del segundo vector
    printf("Ingrese los elementos del segundo vector:\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i+1);
        scanf("%d", &vectorB[i]);
    }

    // Sumar los vectores y guardar el resultado en el tercer vector
    for (int i = 0; i < n; i++) {
        resultado[i] = vectorA[i] + vectorB[i];
    }

    // Resultado
    printf("La suma de los vectores es:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}

