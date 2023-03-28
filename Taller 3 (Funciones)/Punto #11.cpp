//Punto #11

#include <stdio.h>
#include <string.h>

void encriptar(char cadena[]);

int main() {
    char cadena[100];

    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);

    printf("La cadena encriptada es: ");
    encriptar(cadena);
    printf("%s\n", cadena);

    return 0;
}

void encriptar(char cadena[]) {
    int longitud = strlen(cadena);
    for (int i = 0; i < longitud; i++) {
        if (cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = 'a' + ((cadena[i] - 'a' + 13) % 26);
        } else if (cadena[i] >= 'A' && cadena[i] <= 'Z') {
            cadena[i] = 'A' + ((cadena[i] - 'A' + 13) % 26);
        }
    }
}


