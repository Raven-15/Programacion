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

FILE *arc1;
FILE *arc2;


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

void agregarLibro() {
	
	libro library;
	printf("Ingrese el t%ctulo del libro: ", 161);
	fflush(stdin);
	gets(library.titulo);
	printf("Ingrese el autor del libro: ");
	gets(library.autor);
	fflush(stdin);
	printf("Ingrese el n%cmero de p%cginas: ", 160);
	scanf("%d", &library.numPag);
	
	library.is_valid = true;
	library.disponible = true;

	arc1 = fopen("libro.txt", "a");
	if(arc1 == NULL) {
		printf("Error al abrir el archivo.\n");
		exit(EXIT_FAILURE);
	}else {
		fwrite(&library, sizeof(library), 1, arc1);
		fclose(arc1);
		arc1 = NULL;
	}
	printf("T%ctulo: %s\n", 161, library.titulo);
	printf("Autor: %s\n", library.autor);
	printf("N%cmero de p%cginas: %d\n", 163, 160, library.numPag);
}

void mostrarBiblioteca() {
	libro biblioteca[MAX_LIBROS];
	int numeroLibros = 0;
	
	arc2 = fopen("libro.txt", "r");
	
	if(arc2 == NULL) {
		printf("Error al abrir el archivo.\n");
		exit(EXIT_FAILURE);
	}else {
		while(fread(&biblioteca[numeroLibros], sizeof(libro), 1, arc2) == 1) {
			numeroLibros++;
		}
		fclose(arc2);
		arc2 = NULL;
	}
	printf("La casa del Libro:\n");
	for(int j = 0; j < numeroLibros; j++) {
		printf("Autor: %s\n", biblioteca[j].autor);
		printf("T%ctulo: %s\n", 161, biblioteca[j].titulo);
		printf("N%cmero de p%cginas:%d\n", 163, 160, biblioteca[j].numPag);
		printf("\n-------------------------------\n");
	}
}

const char* boolToString(bool value) {
    return value ? "Si" : "No";
}

char tuper(char letter){
    if(letter >= 97 && letter <= 122)
        letter = letter - 32;
    return letter;
}

void borrarLibro() {
    char titulo[MAX_TITULO];
    printf("\nPor favor ingresar el título del libro a borrar: ");
    scanf("%s", titulo);

    FILE *arc3 = fopen("libro.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arc3 == NULL || temp == NULL) {
        printf("Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    } else {
        libro book;
        int encontrado = 0;

        while (fread(&book, sizeof(book), 1, arc3) == 1) {
            if (strcmp(book.titulo, titulo) != 0) {
                fwrite(&book, sizeof(book), 1, temp);
            } else {
                encontrado = 1;
            }
        }

        fclose(arc3);
        fclose(temp);

        if (encontrado) {
            remove("libro.txt");
            rename("temp.txt", "libro.txt");
            printf("El libro con título %s ha sido borrado exitosamente.\n", titulo);
        } else {
            remove("temp.txt");
            printf("No se encontró un libro con el título ingresado.\n");
        }
    }
}

void borrarCliente() {
    int code;
    printf("\nPor favor ingresar la identificación del cliente a borrar: ");
    scanf("%d", &code);

    FILE *arc3 = fopen("usuario.txt", "r");
    FILE *temp = fopen("temp.txt", "w");

    if (arc3 == NULL || temp == NULL) {
        printf("Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    } else {
        usuario client;
        int encontrado = 0;

        while (fread(&client, sizeof(client), 1, arc3) == 1) {
            if (client.code != code) {
                fwrite(&client, sizeof(client), 1, temp);
            } else {
                encontrado = 1;
            }
        }

        fclose(arc3);
        fclose(temp);

        if (encontrado) {
            remove("usuario.txt");
            rename("temp.txt", "usuario.txt");
            printf("El cliente con identificación %d ha sido borrado exitosamente.\n", code);
        } else {
            remove("temp.txt");
            printf("No se encontró un cliente con la identificación ingresada.\n");
        }
    }
}
