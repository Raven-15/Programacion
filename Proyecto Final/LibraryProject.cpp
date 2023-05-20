#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca.h"



int main() {
	
	struct Usuario usuarios[MAX_USUARIOS];
    int numeroUsuarios = 0;
	
    struct Libro biblioteca[MAX_LIBROS];
    int numeroLibros = 0;


    agregarLibro(biblioteca, &numeroLibros, 1, "Del Amor y Otros Demonios", "Gabriel Garcia Marquez", 1994);
    agregarLibro(biblioteca, &numeroLibros, 2, "Ana Frank", "Melissa Muller", 1998);
    agregarLibro(biblioteca, &numeroLibros, 3, "Don Quijote de la Mancha", "Miguel de Cervantes", 1604 - 1605);

    agregarUsuario(usuarios, &numeroUsuarios, 1, "Angelica Piedrahita");
    agregarUsuario(usuarios, &numeroUsuarios, 2, "Sara A. Caballero");
    agregarUsuario(usuarios, &numeroUsuarios, 2, "Francisco. C");

    prestarLibro(biblioteca, numeroLibros, 1, usuarios, numeroUsuarios);
    prestarLibro(biblioteca, numeroLibros, 2, usuarios, numeroUsuarios);
    prestarLibro(biblioteca, numeroLibros, 3, usuarios, numeroUsuarios);

    devolverLibro(biblioteca, numeroLibros, 1, usuarios, numeroUsuarios);


    mostrarBiblioteca(biblioteca, numeroLibros);
    mostrarUsuarios(usuarios, numeroUsuarios);

    guardarBiblioteca(biblioteca, numeroLibros, "biblioteca.dat");
    guardarUsuarios(usuarios, numeroUsuarios, "usuarios.dat");

    cargarBiblioteca(biblioteca, &numeroLibros, "biblioteca.dat");
    cargarUsuarios(usuarios, &numeroUsuarios, "usuarios.dat");

    mostrarBiblioteca(biblioteca, numeroLibros);
    mostrarUsuarios(usuarios, numeroUsuarios);

    return 0;
}
