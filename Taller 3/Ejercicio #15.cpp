//Ejercicio #15

#include <stdio.h>

int main (){
	int i, multiplo, suma = 0;
	for(int i = 1; i <= 20; i++) {
		
		multiplo = i * 3;
        printf("%d\n", multiplo);
        
        suma += multiplo;
    }
    printf("La suma de los primeros 20 multiplos de 3 es: %d\n", suma);
    
    return 0;
}
