//Angelica Punto #3

#include <stdio.h>

#define TAMANO_VECTOR 100

int main() {
    int numeros[TAMANO_VECTOR];
    int i, menores_10=0, entre_10_30=0, entre_31_60=0, mayores_60=0;

    // Leer los numeros y almacenarlos en el vector
    for (i = 0; i < TAMANO_VECTOR; i++) {
        printf("Ingrese el elemento %d: ", i+1);
        scanf("%d", &numeros[i]);
    }

    // Clasificar los numeros según su valor
    for (i = 0; i < TAMANO_VECTOR; i++) {
        if (numeros[i] < 10) {
            menores_10++;
        } else if (numeros[i] >= 10 && numeros[i] <= 30) {
            entre_10_30++;
        } else if (numeros[i] >= 31 && numeros[i] <= 60) {
            entre_31_60++;
        } else {
            mayores_60++;
        }
    }

    // Mostrar los resultados
    printf("Cantidad de elementos menores a 10: %d\n", menores_10);
    printf("Cantidad de elementos entre 10 y 30: %d\n", entre_10_30);
    printf("Cantidad de elementos entre 31 y 60: %d\n", entre_31_60);
    printf("Cantidad de elementos mayores a 60: %d\n", mayores_60);

    return 0;
}

