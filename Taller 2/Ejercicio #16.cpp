//Ejercicio #16

#include <stdio.h>

int main() {
    int n, 
	int numero = 3;
	int suma = 0;
    float promedio;
    
    printf("Angelica digite un numero entero: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        suma += numero;
        numero += 3;
    }
    
    int promedio = suma / n;
    
    printf("El promedio entero de los primeros %d multiplos de 3 es: %d\n", n, promedio);
    
    return 0;
}
