#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"


#define MAX_LIBROS 200
#define MAX_TITULO 200
#define MAX_AUTOR 100
#define MAX_USUARIOS 200

void agregarLibro(struct Libro *biblioteca, int *numeroLibros, int codigo, const char *titulo, const char *autor, int anioPublicacion) {
    if (*numeroLibros < MAX_LIBROS) {
        struct Libro nuevoLibro;
        nuevoLibro.codigo = codigo;
        strncpy(nuevoLibro.titulo, titulo, MAX_TITULO);
        strncpy(nuevoLibro.autor, autor, MAX_AUTOR);
        nuevoLibro.anioPublicacion = anioPublicacion;
        nuevoLibro.disponible = 1;

        biblioteca[*numeroLibros] = nuevoLibro;
        (*numeroLibros)++;

        printf("Libro agregado correctamente.\n");
    } else {
        printf("No se pueden agregar más libros. La biblioteca está llena.\n");
    }
}

void mostrarBiblioteca(struct Libro *biblioteca, int numeroLibros) {
    printf("Biblioteca:\n");
    for (int i = 0; i < numeroLibros; i++) {
        printf("Código: %d\n", biblioteca[i].codigo);
        printf("Título: %s\n", biblioteca[i].titulo);
        printf("Autor: %s\n", biblioteca[i].autor);
        printf("Año en que se publico el libro: %d\n", biblioteca[i].anioPublicacion);
        printf("Disponibilidad del libro: %s\n", biblioteca[i].disponible ? "Sí" : "No");
        printf("------------------------------\n");
    }
}

void buscarLibro(struct Libro *biblioteca, int numeroLibros, const char *titulo) {
    int encontrado = 0;
    printf("Resultado de la búsqueda:\n");
    for (int i = 0; i < numeroLibros; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            printf("Código: %d\n", biblioteca[i].codigo);
            printf("Título: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Año de publicación: %d\n", biblioteca[i].anioPublicacion);
            printf("Disponible: %s\n", biblioteca[i].disponible ? "Sí" : "No");
            printf("------------------------------\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontro ningún libro con el título especificado.\n");
    }
}

void prestarLibro(struct Libro *biblioteca, int numeroLibros, int codigo, struct Usuario *usuarios, int numeroUsuarios) {
    int libroEncontrado = 0;
    for (int i = 0; i < numeroLibros; i++) {
        if (biblioteca[i].codigo == codigo) {
            libroEncontrado = 1;
            if (biblioteca[i].disponible) {
                int usuarioEncontrado = 0;
                for (int j = 0; j < numeroUsuarios; j++) {
                    if (usuarios[j].id == 0) {
                        printf("El libro se ha prestado al usuario \"%s\".\n", usuarios[j].nombre);
                        usuarios[j].id = codigo;
                        strncpy(usuarios[j].nombre, biblioteca[i].titulo, MAX_TITULO);
                        biblioteca[i].disponible = 0;
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
    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].codigo == codigo) {
            libroEncontrado = 1;
            if (!biblioteca[i].disponible) {
                int usuarioEncontrado = 0;
                for (int j = 0; j < numeroUsuarios; j++) {
                    if (usuarios[j].id == codigo) {
                        printf("El libro \"%s\" ha sido devuelto.\n", usuarios[j].nombre);
                        usuarios[j].id = 0;
                        usuarios[j].nombre[0] = '\0';
                        biblioteca[i].disponible = 1;
                        usuarioEncontrado = 1;
                        break;
                    }
                }
                if (!usuarioEncontrado) {
                    printf("No se ha encontrado ningun usuario asociado a este codigo.\n");
                }
            } else {
                printf("El libro ya esta disponible en la biblioteca.\n");
            }
            break;
        }
    }
    if (!libroEncontrado) {
        printf("a este codigo no se encuentro ningun libro asociado.\n");
    }
}

void agregarUsuario(struct Usuario *usuarios, int *numeroUsuarios, int id, const char *nombre) {
    if (*numUsuarios < MAX_USUARIOS) {
        struct Usuario nuevoUsuario;
        nuevoUsuario.id = id;
        strncpy(nuevoUsuario.nombre, nombre, MAX_AUTOR);

        usuarios[*numUsuarios] = nuevoUsuario;
        (*numUsuarios)++;

        printf("Usuario registrado correctamente.\n");
    } else {
        printf("No se pueden agregar mas usuarios. La lista de usuarios esta llena.\n");
    }
}

void mostrarUsuarios(struct Usuario *usuarios, int numUsuarios) {
    printf("Usuarios:\n");
    for (int i = 0; i < numeroUsuarios; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nombre: %s\n", usuarios[i].nombre);
        printf("------------------------------\n");
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

