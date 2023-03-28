//Angelica Punto #1

#include <stdio.h>

#define MAX_NUMEROS 50

int main() {
    int N, num;
    //Declarar vectores y longitug maxima
    int V1[MAX_NUMEROS], V2[MAX_NUMEROS], V3[MAX_NUMEROS];
    int a, b, c;

    printf("Ingrese maximo 50 numeros: ");
    scanf("%d", &N);

    // Inicializar contador de cada vector
    a = b = c = 0;

    for (int n = 0; n < N; n++) {
        printf("Ingrese un numero entero: ");
        scanf("%d", &num);

        if (0 <= num && num <= 10) {
            V1[a++] = num;
        } else if (11 <= num && num <= 20) {
            V2[b++] = num;
        } else if (num > 20) {
            V3[c++] = num;
        }
    }

    // Imprimir vectores
    printf("Vector 1: ");
    for (int l = 0; l < a; l++) {
        printf("%d ", V1[l]);
    }
    printf("\n");

    printf("Vector 2: ");
    for (int l = 0; l < b; l++) {
        printf("%d ", V2[l]);
    }
    printf("\n");

    printf("Vector 3: ");
    for (int l = 0; l < c; l++) {
        printf("%d ", V3[l]);
    }
    printf("\n");

    return 0;
}

