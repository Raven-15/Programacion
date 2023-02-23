//Ejercicio #18

#include <stdio.h>

int main() {
    int x, y, i;

    printf("Angelica escriba el primer numero: ");
    scanf("%d", &x);

    printf("Por favor escriba el segundo numero: ");
    scanf("%d", &y);

    printf("Los multiplos de 5 entre %d y %d son:\n", x, y);

    for (i = x; i <= y; i++) {
        if (i % 5 == 0) {
            printf("%d\n", i);
        }
    }

    return 0;
}
