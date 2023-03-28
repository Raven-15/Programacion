//Punto #9

#include <stdio.h>
#include <math.h>

float aproximar(float numero, char tipo);

int main() {
    float numero = 3.14159;
    char tipo = 'r';

    printf("Ingrese un numero: ");
    scanf("%f", &numero);
    fflush(stdin);

    printf("Ingrese el tipo de aproximacion (r para redondeo, t para truncamiento, c para corte): ");
    scanf("%c", &tipo);

    printf("El numero %f aproximado %f es: %f\n", aproximar, numero, tipo);

    return 0;
}

float aproximar(float numero, char tipo) {
    switch (tipo) {
        case 'r': //Redondeo
            numero = round(numero);
        case 't': //trunk
            numero = trunc(numero);
        case 'c': //Ceil
            numero = ceil (numero);
		case 'f': //Floor
			numero = floor(numero);
        default:
            printf("Tipo de aproximacion invalido.\n");
            return numero;
    }
}

