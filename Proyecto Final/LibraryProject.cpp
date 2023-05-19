#include "biblioteca.h"
#include <stdio.h>

int main() {
    struct Libro biblioteca[MAX_LIBROS];
    int numLibros = 0;

    struct Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = 0;

    agregarLibro(biblioteca, &numLibros, 1, "El gran Gatsby", "F. Scott Fitzgerald", 1925);
    agregarLibro(biblioteca, &numLibros, 2, "1984", "George Orwell", 1949);
    agregarLibro(biblioteca, &numLibros, 3, "Matar a un ruiseñor", "Harper Lee", 1960);

    agregarUsuario(usuarios, &numUsuarios, 1, "Juan Pérez");
    agregarUsuario(usuarios, &numUsuarios, 2, "María Gómez");

    prestarLibro(biblioteca, numLibros, 1, usuarios, numUsuarios);
    prestarLibro(biblioteca, numLibros, 2, usuarios, numUsuarios);

    mostrarBiblioteca(biblioteca, numLibros);
    mostrarUsuarios(usuarios, numUsuarios);

    guardarBiblioteca(biblioteca, numLibros, "biblioteca.dat");
    guardarUsuarios(usuarios, numUsuarios, "usuarios.dat");

    cargarBiblioteca(biblioteca, &numLibros, "biblioteca.dat");
    cargarUsuarios(usuarios, &numUsuarios, "usuarios.dat");

    mostrarBiblioteca(biblioteca, numLibros);
    mostrarUsuarios(usuarios, numUsuarios);

    return 0;
}

