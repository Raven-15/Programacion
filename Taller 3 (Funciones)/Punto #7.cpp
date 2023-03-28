//Punto #7

#include <stdio.h>

char to_uppercase(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A'; 
    } else {
        return c; 
    }
}

int main() {
    char c;
    printf("Ingrese un caracter en minuscula: ");
    scanf("%c", &c);
    printf("El equivalente en mayuscula es: %c\n", to_uppercase(c));
    return 0;
}
