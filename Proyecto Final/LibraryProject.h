#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#define MAX_LIBROS 200
#define MAX_TITULO 200
#define MAX_AUTOR 100
#define MAX_USUARIOS 200

struct Libro {
	int codigo;
	anioPublicacion;
	int disponible;
	char titulo [MAX_TITULO];
	char autor [MAX_AUTOR];
};

struct Usuario {
    int cedula;
    char nombre[MAX_AUTOR];
};

void agregarLibro(struct Libro *biblioteca, int *numeroLibros, int codigo, const char *titulo, const char *autor, int anioPublicacion);
void mostrarBiblioteca(struct Libro *biblioteca, int numeroLibros);
void buscarLibro(struct Libro *biblioteca, int numeroLibros, const char *titulo);
void prestarLibro(struct Libro *biblioteca, int numeroLibros, int codigo, struct Usuario *usuarios, int numUsuarios);
void devolverLibro(struct Libro *biblioteca, int numeroLibros, int codigo);
void agregarUsuario(struct Usuario *usuarios, int *numeroUsuarios, int id, const char *nombre);
void mostrarUsuarios(struct Usuario *usuarios, int numeroUsuarios);
void guardarBiblioteca(struct Libro *biblioteca, int numeroLibros, const char *archivo);
void cargarBiblioteca(struct Libro *biblioteca, int *numeroLibros, const char *archivo);
void guardarUsuarios(struct Usuario *usuarios, int numeroUsuarios, const char *archivo);
void cargarUsuarios(struct Usuario *usuarios, int *numeroUsuarios, const char *archivo);

#endif


