#include <stdio.h>
#include <stdlib.h>
#include "LibraryProject.h"

#define MAX_LIBROS 200 
#define MAX_TITULO 100 
#define MAX_AUTOR 50 

FILE *arc1;
FILE *arc2;


typedef struct {
	bool is_valid;
	char titulo[MAX_TITULO];
	char autor[MAX_AUTOR];
	bool disponible;
	int numPag;
	
}libro;

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

int menu () {
	
	int opcion;
	printf("\n LA CASA DEL LIBRO\n\n");
	printf("1. Agregar libro\n");
	printf("2. Mostrar biblioteca\n");
	printf("3. Buscar libro\n");
	printf("4. Prestar libro\n");
	printf("5. Devolver libro\n");
	printf("6. Agregar usuario\n");
	printf("7. Buscar usuarios\n");
	printf("8. Eliminar usuario\n");
	printf("9. Salir\n");
	printf("INGRESE UNA OPCION ENTRE 1 Y 11: ");
	fflush(stdin);
	scanf("%d", &opcion);
	
	return opcion;
}
