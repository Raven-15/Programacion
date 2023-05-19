#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_TITULO 100
#define MAX_AUTOR 50

struct Libro {
    int codigo;
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int anioPublicacion;
    int disponible;
};

void agregarLibro(struct Libro *biblioteca, int *numLibros, int codigo, const char *titulo, const char *autor, int anioPublicacion);
void mostrarBiblioteca(struct Libro *biblioteca, int numLibros);
void buscarLibro(struct Libro *biblioteca, int numLibros, const char *titulo);
void prestarLibro(struct Libro *biblioteca, int numLibros, int codigo);
void devolverLibro(struct Libro *biblioteca, int numLibros, int codigo);

#endif

