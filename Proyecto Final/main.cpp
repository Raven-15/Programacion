#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"


#define MAX_LIBROS 200
#define MAX_TITULO 200
#define MAX_AUTOR 100
#define MAX_USUARIOS 200


struct Usuario {
	int cedula
	char nombre [MAX_AUTOR];
	
};

struct Libro {
	int codigo;
	anioPublicacion;
	int disponible;
	char titulo [MAX_TITULO];
	char autor [MAX_AUTOR];
};


void agregarLibro(struct Libro *biblioteca, int *numeroLibros, int codigo, const char *titulo, const char *autor, int anioPublicacion) {
    if (*numeroLibros < MAX_LIBROS) {
        struct Libro nuevoLibro;
        nuevoLibro.codigo = codigo;
        strncpy(nuevoLibro.titulo, titulo, MAX_TITULO);
        strncpy(nuevoLibro.autor, autor, MAX_AUTOR);
        nuevoLibro.disponible = 1;
        nuevoLibro.anioPublicacion = anioPublicacion;

        biblioteca[*numeroLibros] = nuevoLibro;
        (*numeroLibros)++;

        printf("Libro agregado correctamente.\n");
    } else {
        printf("No se pueden agregar más libros. La biblioteca está llena.\n");
    }
}

void mostrarBiblioteca(struct Libro *biblioteca, int numeroLibros) {
    printf("Biblioteca:\n");
    for (int j = 0; j < numeroLibros; j++) {
    	printf("Autor: %s\n", biblioteca[j].autor);
        printf("Código: %d\n", biblioteca[j].codigo);
        printf("Título: %s\n", biblioteca[ij.titulo);
        printf("Año en que se publico el libro: %d\n", biblioteca[j].anioPublicacion);
        printf("Disponibilidad del libro: %s\n", biblioteca[j].disponible ? "Si esta disponible" : "No esta disponible");
        printf("\n--------------------------\n");
    }
}

void buscarLibro(struct Libro *biblioteca, int numeroLibros, const char *titulo) {
    int encontrado = 0;
    printf("Resultado de la búsqueda:\n");
    for (int j = 0; j < numeroLibros; j++) {
        if (strcmp(biblioteca[j].titulo, titulo) == 0) {
        	printf("Autor: %s\n", biblioteca[j].autor);
            printf("Código: %d\n", biblioteca[j].codigo);
            printf("Título: %s\n", biblioteca[j].titulo);
            printf("Año de publicación: %d\n", biblioteca[j].anioPublicacion);
            printf("Disponible: %s\n", biblioteca[j].disponible ? "Si esta disponible" : "No esta disponible");
            printf("\n--------------------------\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontro el  libro con el titulo ingresado.\n");
    }
}

void prestarLibro(struct Libro *biblioteca, int numeroLibros, int codigo, struct Usuario *usuarios, int numeroUsuarios) {
    int libroEncontrado = 0;
    for (int j = 0; j < numeroLibros; j++) {
        if (biblioteca[j].codigo == codigo) {
            libroEncontrado = 1;
            if (biblioteca[j].disponible) {
                int usuarioEncontrado = 0;
                for (int i = 0; i < numeroUsuarios; i++) {
                    if (usuarios[i].id == 0) {
                        printf("El libro se ha prestado al usuario \"%s\".\n", usuarios[i].nombre);
                        usuarios[i].id = codigo;
                        strncpy(usuarios[i].nombre, biblioteca[i].titulo, MAX_TITULO);
                        biblioteca[j].disponible = 0;
                        usuarioEncontrado = 1;
                        break;
                    }
                }
                if (!usuarioEncontrado) {
                    printf("No hay usuarios disponibles para prestar el libro.\n");
                }
            } else {
                printf("El libro no esta disponible en este momento.\n");
            }
            break;
        }
    }
    if (!libroEncontrado) {
        printf("No se encontro ningun libro con el codigo especificado.\n");
    }
}

void devolverLibro(struct Libro *biblioteca, int numeroLibros, int codigo, struct Usuario *usuarios, int numeroUsuarios) {
    int libroEncontrado = 0;
    for (int j = 0; j < numLibros; j++) {
        if (biblioteca[j].codigo == codigo) {
            libroEncontrado = 1;
            if (!biblioteca[j].disponible) {
                int usuarioEncontrado = 0;
                for (int i = 0; i < numeroUsuarios; j++) {
                    if (usuarios[i].id == codigo) {
                        printf("El libro \"%s\" ha sido devuelto.\n", usuarios[i].nombre);
                        usuarios[i].id = 0;
                        usuarios[i].nombre[0] = '\0';
                        biblioteca[j].disponible = 1;
                        usuarioEncontrado = 1;
                        break;
                    }
                }
                if (!usuarioEncontrado) {
                    printf("No se ha encontrado ningun usuario con el codigo especificado.\n");
                }
            } else {
                printf("El libro ya esta disponible en la biblioteca.\n");
            }
            break;
        }
    }
    if (!libroEncontrado) {
        printf("A este codigo no se encuentro ningun libro asociado.\n");
    }
}

void agregarUsuario(struct Usuario *usuarios, int *numeroUsuarios, int id, const char *nombre) {
    if (*numeroUsuarios < MAX_USUARIOS) {
        struct Usuario nuevoUsuario;
        nuevoUsuario.id = id;
        strncpy(nuevoUsuario.nombre, nombre, MAX_AUTOR);

        usuarios[*numeroUsuarios] = nuevoUsuario;
        (*numeroUsuarios)++;

        printf("Usuario registrado correctamente.\n");
    } else {
        printf("No se pueden agregar mas usuarios. La lista esta llena.\n");
    }
}

void mostrarUsuarios(struct Usuario *usuarios, int numUsuarios) {
    printf("Usuarios:\n");
    for (int j = 0; j < numeroUsuarios; j++) {
        printf("Cedula: %d\n", usuarios[j].id);
        printf("Nombre: %s\n", usuarios[j].nombre);
        printf("\n-------------------------\n");
    }
}

void guardarBiblioteca(struct Libro *biblioteca, int numeroLibros, const char *archivo) {
    FILE *file = fopen(archivo, "wb");
    if (file) {
        fwrite(biblioteca, sizeof(struct Libro), numeroLibros, file);
        fclose(file);
        printf("Datos de la biblioteca guardados correctamente.\n");
    } else {
        printf("No se pudo abrir el archivo para guardar los datos.\n");
    }
}

void cargarBiblioteca(struct Libro *biblioteca, int *numeroLibros, const char *archivo) {
    FILE *file = fopen(archivo, "rb");
    if (file) {
        fread(biblioteca, sizeof(struct Libro), MAX_LIBROS, file);
        fclose(file);
        printf("Datos guardados correctamnete.\n");
        *numeroLibros = MAX_LIBROS;
    } else {
        printf("No se guardaron los datos.\n");
    }
}

void guardarUsuarios(struct Usuario *usuarios, int numeroUsuarios, const char *archivo) {
    FILE *file = fopen(archivo, "wb");
    if (file) {
        fwrite(usuarios, sizeof(struct Usuario), numeroUsuarios, file);
        fclose(file);
        printf("Datos de los usuarios guardados correctamente en el archivo.\n");
    } else {
        printf("No se pudo abrir el archivo para guardar los datos de los usuarios.\n");
    }
}

void cargarUsuarios(struct Usuario *usuarios, int *numeroUsuarios, const char *archivo) {
    FILE *file = fopen(archivo, "rb");
    if (file) {
        fread(usuarios, sizeof(struct Usuario), MAX_USUARIOS, file);
        fclose(file);
        printf("Datos de los usuarios cargados correctamente desde el archivo.\n");
        *numeroUsuarios = MAX_USUARIOS;
    } else {
        printf("No se pudo abrir el archivo para cargar los datos de los usuarios.\n");
    }
}

