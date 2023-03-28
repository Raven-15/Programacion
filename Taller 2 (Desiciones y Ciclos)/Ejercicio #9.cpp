//Ejercicio #9

#include <stdio.h>

int main() {
	
    printf("Los numeros terminados en 6 comprendidos entre 25 y 205 son:\n");

    for (int i = 26; i <= 206; i += 10) {
        printf("%d ", i);
        
    }
    printf("\n");

    return 0;
}

