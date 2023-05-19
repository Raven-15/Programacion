#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_TITULO 100
#define MAX_AUTOR 50
#define MAX_USUARIOS 100

struct Libro {
    int codigo;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int anioPublicacion;
    int disponible;
};

struct Usuario {
    int id;
    char nombre[MAX_AUTOR];
};

void agregarLibro(struct Libro *biblioteca, int *numLibros, int codigo, const char *titulo, const char *autor, int anioPublicacion);
void mostrarBiblioteca(struct Libro *biblioteca, int numLibros);
void buscarLibro(struct Libro *biblioteca, int numLibros, const char *titulo);
void prestarLibro(struct Libro *biblioteca, int numLibros, int codigo, struct Usuario *usuarios, int numUsuarios);
void devolverLibro(struct Libro *biblioteca, int numLibros, int codigo);
void agregarUsuario(struct Usuario *usuarios, int *numUsuarios, int id, const char *nombre);
void mostrarUsuarios(struct Usuario *usuarios, int numUsuarios);
void guardarBiblioteca(struct Libro *biblioteca, int numLibros, const char *archivo);
void cargarBiblioteca(struct Libro *biblioteca, int *numLibros, const char *archivo);
void guardarUsuarios(struct Usuario *usuarios, int numUsuarios, const char *archivo);
void cargarUsuarios(struct Usuario *usuarios, int *numUsuarios, const char *archivo);

#endif

