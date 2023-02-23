//Ejercicio #31

#include <stdio.h>

int main() {
    int numero, suma = 0, conteo = 0;

    printf("Angelica digite el numero 0 para finalizar: ");

    while (1) {
        scanf("%d", &numero);

        if (numero == 0) {
            break;
        }

        if (numero % 10 == 5) {
            suma += numero;
            conteo++;
        }
    }

    if (conteo == 0) {
        printf("No se ingresaron numeros terminados en 5\n");
    } else {
        float promedio = (float) suma / conteo;
        printf("El promedio de los numeros terminados en 5 es %.2f\n", promedio);
    }

    return 0;
}

