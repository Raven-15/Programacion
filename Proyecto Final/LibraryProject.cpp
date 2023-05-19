#include "biblioteca.h"
#include <stdio.h>

int main() {
    struct Libro biblioteca[MAX_LIBROS];
    int numLibros = 0;

    agregarLibro(biblioteca, &numLibros, 1, "El principito", "Antoine de Saint-Exupéry", 1943);
    agregarLibro(biblioteca, &numLibros, 2, "Cien años de soledad", "Gabriel García Márquez", 1967);
    agregarLibro(biblioteca, &numLibros, 3, "Don Quijote de la Mancha", "Miguel de Cervantes Saavedra", 1605);

    mostrarBiblioteca(biblioteca, numLibros);

    buscarLibro(biblioteca, numLibros, "Cien años de soledad");

    prestarLibro(biblioteca, numLibros, 2);
    mostrarBiblioteca(biblioteca, numLibros);

    devolverLibro(biblioteca, numLibros, 2);
    mostrarBiblioteca(biblioteca, numLibros);

    return 0;
}

