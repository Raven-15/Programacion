//Ejercicio #17

#include <stdio.h>

int main() {
    int x, y, i;
    float promedio_multiplos_2 = 0, promedio_multiplos_5 = 0;
    
    printf("Angelica ingrese el valor de x: ");
    scanf("%d", &x);
    
    printf("Angelica ingrese el valor de y: ");
    scanf("%d", &y);
    
    
    for(i = 1; i <= x; i++) {
        promedio_multiplos_2 += 2*i;
    }
    promedio_multiplos_2 /= x;
    
    
    for(i = 1; i <= y; i++) {
        promedio_multiplos_5 += 5*i;
    }
    promedio_multiplos_5 /= y;
    
    
    if(promedio_multiplos_2 > promedio_multiplos_5) {
        printf("El promedio de los primeros %d multiplos de 2 es mayor que el promedio de los primeros %d multiplos de 5\n", x, y);
    } else {
        printf("El promedio de los primeros %d multiplos de 2 es menor o igual que el promedio de los primeros %d multiplos de 5\n", x, y);
    }
    
    return 0;
}
