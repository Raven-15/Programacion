//ejercicio #27

#include <stdio.h>

int main() {
    int numero1, numero2;
    printf("Angelica escriba dos numeros enteros: ");
    scanf("%d %d", &numero1, &numero2);
    int digitos1 = 0;
    int digitos2 = 0;
    int temp1 = numero1;
    int temp2 = numero2;
    while (temp1 != 0) {
        digitos1++;
        temp1 /= 10;
    }
    while (temp2 != 0) {
        digitos2++;
        temp2 /= 10;
    }
    if (digitos1 > digitos2) {
        printf("%d Angelica, tiene mas digitos que %d\n", numero1, numero2);
    } else if (digitos2 > digitos1) {
        printf("%d Angelica tiene mas digitos que %d\n", numero2, numero1);
    } else {
        printf("%d y %d tienen la misma cantidad de digitos\n", numero1, numero2);
    }
    return 0;
}

