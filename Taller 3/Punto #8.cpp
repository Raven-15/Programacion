//Punto #8

//Punto #7

#include <stdio.h>

char to_uppercase(char c) {
    if (c >= 'A' && c <= 'zZ') {
        return c + ('a' - 'A'); 
    } else {
        return c; 
    }
}

int main() {
    char c;
    printf("Ingrese un caracter en mayuscula: ");
    scanf("%c", &c);
    printf("El equivalente en minuscula es: %c\n", to_uppercase(c));
    return 0;
}
