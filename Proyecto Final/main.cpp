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
    int encontrado = 0;
    printf("Resultado de la b�squeda:\n");
    for (int i = 0; i < numLibros; i++) {
        if (strcmp(biblioteca[i].titulo, titulo) == 0) {
            printf("C�digo: %d\n", biblioteca[i].codigo);
            printf("T�tulo: %s\n", biblioteca[i].titulo);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("A�o de publicaci�n: %d\n", biblioteca[i].anioPublicacion);
            printf("Disponible: %s\n", biblioteca[i].disponible ? "S�" : "No");
            printf("------------------------------\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontr� ning�n libro con el t�tulo especificado.\n");
    }
}

void prestarLibro(struct Libro *biblioteca, int numLibros, int codigo, struct Usuario *usuarios, int numUsuarios) {
    int libroEncontrado = 0;
    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].codigo == codigo) {
            libroEncontrado = 1;
            if (biblioteca[i].disponible) {
                int usuarioEncontrado = 0;
                for (int j = 0; j < numUsuarios; j++) {
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
                printf("El libro no est� disponible en este momento.\n");
            }
            break;
        }
    }
    if (!libroEncontrado) {
        printf("No se encontr� un libro con el c�digo especificado.\n");
    }
}

void devolverLibro(struct Libro *biblioteca, int numLibros, int codigo, struct Usuario *usuarios, int numUsuarios) {
    int libroEncontrado = 0;
    for (int i = 0; i < numLibros; i++) {
        if (biblioteca[i].codigo == codigo) {
            libroEncontrado = 1;
            if (!biblioteca[i].disponible) {
                int usuarioEncontrado = 0;
                for (int j = 0; j < numUsuarios; j++) {
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
                    printf("No se encontr� un usuario asociado a este libro.\n");
                }
            } else {
                printf("El libro ya est� disponible en la biblioteca.\n");
            }
            break;
        }
    }
    if (!libroEncontrado) {
        printf("No se encontr� un libro con el c�digo especificado.\n");
    }
}

void agregarUsuario(struct Usuario *usuarios, int *numUsuarios, int id, const char *nombre) {
    if (*numUsuarios < MAX_USUARIOS) {
        struct Usuario nuevoUsuario;
        nuevoUsuario.id = id;
        strncpy(nuevoUsuario.nombre, nombre, MAX_AUTOR);

        usuarios[*numUsuarios] = nuevoUsuario;
        (*numUsuarios)++;

        printf("Usuario agregado correctamente.\n");
    } else {
        printf("No se pueden agregar m�s usuarios. La lista de usuarios est� llena.\n");
    }
}

void mostrarUsuarios(struct Usuario *usuarios, int numUsuarios) {
    printf("Usuarios:\n");
    for (int i = 0; i < numUsuarios; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nombre: %s\n", usuarios[i].nombre);
        printf("------------------------------\n");
    }
}

void guardarBiblioteca(struct Libro *biblioteca, int numLibros, const char *archivo) {
    FILE *file = fopen(archivo, "wb");
    if (file) {
        fwrite(biblioteca, sizeof(struct Libro), numLibros, file);
        fclose(file);
        printf("Datos de la biblioteca guardados correctamente en el archivo.\n");
    } else {
        printf("No se pudo abrir el archivo para guardar los datos de la biblioteca.\n");
    }
}

void cargarBiblioteca(struct Libro *biblioteca, int *numLibros, const char *archivo) {
    FILE *file = fopen(archivo, "rb");
    if (file) {
        fread(biblioteca, sizeof(struct Libro), MAX_LIBROS, file);
        fclose(file);
        printf("Datos de la biblioteca cargados correctamente desde el archivo.\n");
        *numLibros = MAX_LIBROS;
    } else {
        printf("No se pudo abrir el archivo para cargar los datos de la biblioteca.\n");
    }
}

void guardarUsuarios(struct Usuario *usuarios, int numUsuarios, const char *archivo) {
    FILE *file = fopen(archivo, "wb");
    if (file) {
        fwrite(usuarios, sizeof(struct Usuario), numUsuarios, file);
        fclose(file);
        printf("Datos de los usuarios guardados correctamente en el archivo.\n");
    } else {
        printf("No se pudo abrir el archivo para guardar los datos de los usuarios.\n");
    }
}

void cargarUsuarios(struct Usuario *usuarios, int *numUsuarios, const char *archivo) {
    FILE *file = fopen(archivo, "rb");
    if (file) {
        fread(usuarios, sizeof(struct Usuario), MAX_USUARIOS, file);
        fclose(file);
        printf("Datos de los usuarios cargados correctamente desde el archivo.\n");
        *numUsuarios = MAX_USUARIOS;
    } else {
        printf("No se pudo abrir el archivo para cargar los datos de los usuarios.\n");
    }
}

