//Ejercicio #11

#include <stdio.h>

int main() {
	
    int numero, primer_digito, segundo_digito;

    printf("Angelica escriba un numero entero de dos digitos: ");
    scanf("%d", &numero);

    
    primer_digito = numero / 10; // Obtener el primer d�gito

    
    segundo_digito = numero % 10; // Obtener el segundo d�gito

    // Determinar cu�l d�gito es el menor y cu�l es el mayor
    int menor = primer_digito < segundo_digito ? primer_digito : segundo_digito;
    int mayor = primer_digito > segundo_digito ? primer_digito : segundo_digito;

    printf("Los enteros comprendidos entre %d y %d son:\n", menor, mayor);

    for (int i = menor; i <= mayor; i++) {
        printf("%d ", i);
        
    }
    
    printf("\n");

    return 0;
    
}

