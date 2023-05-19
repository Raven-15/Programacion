#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"



int main() {
    struct Libro biblioteca[MAX_LIBROS];
    int numLibros = 0;

    struct Usuario usuarios[MAX_USUARIOS];
    int numUsuarios = 0;

    agregarLibro(biblioteca, &numLibros, 1, "Del Amor y Otros Demonios", "Gabriel Garcia Marquez", 1994);
    agregarLibro(biblioteca, &numLibros, 2, "Ana Frank", "Melissa Muller", 1998);
    agregarLibro(biblioteca, &numLibros, 3, "Don Quijore de la Mancha", "Miguel de Cervantes", 1604 - 1605);

    agregarUsuario(usuarios, &numUsuarios, 1, "Angelica Piedrahita");
    agregarUsuario(usuarios, &numUsuarios, 2, "Sara A. Caballero");

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
