#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>   
#include <time.h>    
#include "LibraryProject.h"

#define MAX_LIBROS 200
#define MAX_TITULO 100
#define MAX_AUTOR 50
#define MAX_USUARIOS 200

typedef struct {
    int code;
    char name[MAX_USUARIOS];
    int is_valid;
} usuario;

typedef struct {
    int is_valid;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    char disponible;
    int numPag;
} libro;

typedef struct {
    int is_valid;
    char titulo[MAX_TITULO];
    int code;
    char date_start[128];
    char date_finish[128];
} prestamo;

libro buscarLibro(int print) {
    char titulo[MAX_TITULO];
    libro book;
    int encontrado = 0;

    printf("Por favor ingresar el título del libro: ");
    scanf("%s", titulo);

    FILE *arc3 = fopen("libro.txt", "r");

    if (arc3 == NULL) {
        printf("Error al abrir el archivo.\n");
    } else {
        while (fread(&book, sizeof(book), 1, arc3) == 1) {
            if (strcmp(book.titulo, titulo) == 0) {
                int pos = ftell(arc3);
                if (print) {
                    printf("El puntero se encuentra en la posición: %d\n", pos);

                    printf("Resultado de la búsqueda:\n");
                    printf("Título: %s\n", book.titulo);
                    printf("Autor: %s\n", book.autor);
                    printf("Número de páginas: %d\n", book.numPag);
                    printf("Disponible: %s\n", book.disponible ? "Sí" : "No");
                    printf("--------------------------\n");
                }

                encontrado = 1;
                break;
            }
        }
        fclose(arc3);
    }

    if (!encontrado) {
        printf("No se encontró el libro con el título ingresado.\n");
    }

    return book;
}

usuario agregarUsuario() {
    usuario client;

    printf("\nPor favor ingresar la identificación del cliente: ");
    scanf("%d", &client.code);

    printf("Por favor ingresar el nombre del cliente: ");
    scanf("%s", client.name);

    client.is_valid = 1;

    FILE *arc3 = fopen("usuario.txt", "a");

    if (arc3 == NULL) {
        printf("Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    } else {
        fwrite(&client, sizeof(client), 1, arc3);
        fclose(arc3);
    }

    printf("Documento: %d\n", client.code);
    printf("Nombre: %s\n", client.name);

    return client;
}

usuario buscarUsuario(int code) {
    usuario client;
    int encontrado = 0;
    char confirmation;
    int print = 1;

    printf("Está seguro que la identificación %d está correcta? Si[S]  No[N]: ", code);
    scanf(" %c", &confirmation);
    confirmation = toupper((unsigned char)confirmation);  // Convertir a mayúsculas

    if (confirmation == 'S') {
        FILE *arc3 = fopen("usuario.txt", "rb");

        if (arc3 == NULL) {
            printf("Error al abrir el archivo\n");
        } else {
            while (fread(&client, sizeof(client), 1, arc3)) {
                if (client.code == code) {
                    if (print) {
                        printf("Documento: %d\n", client.code);
                        printf("Nombre: %s\n", client.name);
                        encontrado = 1;
                    }
                    break;
                }
            }
            fclose(arc3);
        }
    }

    if (!encontrado) {
        printf("No se encontró el usuario con la identificación ingresada.\n");
    }

    return client;
}

void prestarLibro() {
    usuario client;
    libro book;
    prestamo loan;
    char confirmation;
    int code;
    int print = 1;

    printf("\nPor favor ingresar la identificación del cliente: ");
    scanf("%d", &code);

    client = buscarUsuario(code);

    if (client.is_valid) {
        book = buscarLibro(print);

        if (book.is_valid) {
            printf("Está seguro que desea prestar el libro %s? Si[S]  No[N]: ", book.titulo);
            scanf(" %c", &confirmation);
            confirmation = toupper((unsigned char)confirmation);  // Convertir a mayúsculas

            if (confirmation == 'S') {
                time_t t = time(NULL);
                struct tm *tm = localtime(&t);
                strftime(loan.date_start, sizeof(loan.date_start), "%Y-%m-%d %H:%M:%S", tm);

                strcpy(loan.titulo, book.titulo);
                loan.code = client.code;
                loan.is_valid = 1;

                FILE *arc3 = fopen("prestamo.txt", "a");

                if (arc3 == NULL) {
                    printf("Error al abrir el archivo\n");
                    exit(EXIT_FAILURE);
                } else {
                    fwrite(&loan, sizeof(loan), 1, arc3);
                    fclose(arc3);
                }

                printf("El libro %s ha sido prestado correctamente.\n", book.titulo);
            }
        }
    }
}

void devolverLibro() {
    usuario client;
    libro book;
    prestamo loan;
    char confirmation;
    int code;
    int print = 1;

    printf("\nPor favor ingresar la identificación del cliente: ");
    scanf("%d", &code);

    client = buscarUsuario(code);

    if (client.is_valid) {
        book = buscarLibro(print);

        if (book.is_valid) {
            printf("Está seguro que desea devolver el libro %s? Si[S]  No[N]: ", book.titulo);
            scanf(" %c", &confirmation);
            confirmation = toupper((unsigned char)confirmation);  // Convertir a mayúsculas

            if (confirmation == 'S') {
                time_t t = time(NULL);
                struct tm *tm = localtime(&t);
                strftime(loan.date_finish, sizeof(loan.date_finish), "%Y-%m-%d %H:%M:%S", tm);

                strcpy(loan.titulo, book.titulo);
                loan.code = client.code;
                loan.is_valid = 1;

                FILE *arc3 = fopen("prestamo.txt", "a");

                if (arc3 == NULL) {
                    printf("Error al abrir el archivo\n");
                    exit(EXIT_FAILURE);
                } else {
                    fwrite(&loan, sizeof(loan), 1, arc3);
                    fclose(arc3);
                }

                printf("El libro %s ha sido devuelto correctamente.\n", book.titulo);
            }
        }
    }
}



int main() {
    int opcion;

    do {
        printf("Seleccione una opción: \n\n");
        printf("1. Agregar usuario\n");
        printf("2. Buscar usuario\n");
        printf("3. Borrar usuario\n");
        printf("4. Agregar libro\n");
        printf("5. Prestar libro\n");
        printf("6. Devolver libro\n");
        printf("7. Borrar libro\n");
        printf("8. Salir\n");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarUsuario();
                break;
            case 2: {
                int code;
                printf("Por favor ingresar la identificación del cliente: ");
                scanf("%d", &code);
                buscarUsuario(code);
                break;
            }
            case 3:
            	borrarCliente();
            	break;
            case 4:
                agregarLibro();
                break;
            case 5:
                prestarLibro();
                break;
            case 6:
                devolverLibro();
                break;
            case 7:
            	borrarLibro();
            	break;
            case 8:
                exit(EXIT_SUCCESS);
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    } while (opcion != 8);

    return 0;
}
