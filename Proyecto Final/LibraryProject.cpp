#include "biblioteca.h"
#include <stdio.h>

int main() {
    struct Libro biblioteca[MAX_LIBROS];
    int numLibros = 0;

    agregarLibro(biblioteca, &numLibros, 1, "El principito", "Antoine de Saint-Exup�ry", 1943);
    agregarLibro(biblioteca, &numLibros, 2, "Cien a�os de soledad", "Gabriel Garc�a M�rquez", 1967);
    agregarLibro(biblioteca, &numLibros, 3, "Don Quijote de la Mancha", "Miguel de Cervantes Saavedra", 1605);

    mostrarBiblioteca(biblioteca, numLibros);

    buscarLibro(biblioteca, numLibros, "Cien a�os de soledad");

    prestarLibro(biblioteca, numLibros, 2);
    mostrarBiblioteca(biblioteca, numLibros);

    devolverLibro(biblioteca, numLibros, 2);
    mostrarBiblioteca(biblioteca, numLibros);

    return 0;
}

