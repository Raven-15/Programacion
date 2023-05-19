#include "biblioteca.h"
#include <stdio.h>
#include <string.h>

#define MAX_LIBROS 100

void agregarLibro(struct Libro *biblioteca, int *numLibros, int codigo, const char *titulo, const char *autor, int anioPublicacion) {
    if (*numLibros < MAX_LIBROS) {
        struct Libro nuevoLibro;
        nuevoLibro.codigo = codigo;
        strncpy(nuevoLibro.titulo, titulo, MAX_TITULO);
        strncpy(nuevoLibro.autor, autor, MAX_AUTOR);
        nuevoLibro.anioPublicacion = anioPublicacion;
        nuevoLibro.disponible = 1;
        
        biblioteca[*numLibros] = nuevoLibro;
        (*numLibros)++;
        
        printf("Libro agregado correctamente.\n");
    } else {
        printf("No se pueden agregar m�s libros. La biblioteca est� llena.\n");
    }
}

void mostrarBiblioteca(struct Libro *biblioteca, int numLibros) {
    printf("Biblioteca:\n");
    for (int i = 0; i < numLibros; i++) {
        printf("C�digo: %d\n", biblioteca[i].codigo);
        printf("T�tulo: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("A�o de publicaci�n: %d\n", biblioteca[i].anioPublicacion);
        printf("Disponible: %s\n", biblioteca[i].disponible ? "S�" : "No");
        printf("------------------------------\n");
    }
}

void buscarLibro(struct Libro *biblioteca, int numLibros, const char *titulo) {
    printf("Resultados de la b�squeda:\n");
    for (int i = 0; i < numLibros; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            printf("C�digo: %d\n", biblioteca[i].codigo);
            printf("T�tulo: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("A�o de publicaci�n: %d\n", biblioteca[i].anioPublicacion);
            printf("Disponible: %s\n", biblioteca[i].disponible ? "S�" : "No");
            printf("------------------------------\n");
        }
    }
}

void prestarLibro(struct Libro *biblioteca, int numLibros, int codigo) {
    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].codigo == codigo) {
            if (biblioteca[i].disponible) {
                biblioteca[i].disponible = 0;
                printf("Libro prestado correctamente.\n");
            } else {
                printf("El libro no est� disponible en este momento.\n");
            }
            return;
        }
    }
    printf("No se encontr� un libro con el c�digo especificado.\n");
}

void devolverLibro(struct Libro *biblioteca, int numLibros, int codigo) {
    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].codigo == codigo) {
            if (!biblioteca[i].disponible) {
                biblioteca[i].disponible = 1;
                printf("Libro devuelto correctamente.\n");
            } else {
                printf("El libro ya est� disponible.\n");
            }
            return;
        }
    }
    printf("No se encontr� un libro con el c�digo especificado.\n");
}

