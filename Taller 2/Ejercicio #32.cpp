//Ejercicio #32

#include <stdio.h>
#include <math.h>

int es_primo(int numero) {
    if (numero < 2) {
        return 0;
    }

    for (int i = 2; i <= sqrt(numero); i++) {
        if (numero % i == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int numero, suma = 0, conteo = 0;

    printf("Angelica digite el numero 0 para finalizar: ");

    while (1) {
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        if (es_primo(numero)) {
            suma += numero;
            conteo++;
        }
    }

    if (conteo == 0) {
        printf("No se ingresaron numeros primos\n");
    } else {
        float promedio = (float) suma / conteo;
        int promedio_entero = round(promedio);
        printf("El promedio entero de los numeros primos es %d\n", promedio_entero);
    }

    return 0;
}

