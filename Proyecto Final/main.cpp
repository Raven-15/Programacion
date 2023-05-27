#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>//para poder usar bool
#include "LibraryProject.h"

#define MAX_LIBROS 200 
#define MAX_TITULO 100 
#define MAX_AUTOR 50 
#define MAX_USUARIOS 200

FILE *arc3;
FILE *arc4;
FILE *arc5;


typedef struct {
	int code;
	char name [MAX_USUARIOS];
	bool is_valid = false;
}usuario;

typedef struct {
	bool is_valid = false;
	char titulo[MAX_TITULO];
	char autor[MAX_AUTOR];
	char disponible;
	int numPag;
	
}libro;

typedef struct {
	bool is_valid = false;
	char titulo[MAX_TITULO];
	int code;
	char date_start[128];
	char date_finish[128] = "";	
}prestamo;

libro buscarLibro(bool print) {
	
	char titulo[MAX_TITULO];
	libro book;
    int encontrado = 0;
    
	printf("Por favor ingresar el t%ctulo del libro: ", 161);
	scanf("%s", &titulo);

	arc3 = fopen("libro.txt", "r");
	
	if(arc3 == NULL) {
		printf("Error al abrir el archivo.\n");
	}else {
		while(fread(&book, sizeof(book), 1, arc3) == 1) {
			if(strcmp(book.titulo, titulo) == 0) {
	        	int pos = ftell(arc3);
	        	if(print){
	        		printf("El puntero se encuentra en la posici%cn: %d\n", 162, pos);
		       
				    printf("Resultado de la b%csqueda:\n", 163);
			    	printf("T%ctulo: %s\n", 161, book.titulo);
			    	printf("Autor: %s\n", book.autor);
			    	printf("N%cmero de p%cginas: %d\n", 163, 160);
			    	printf("Disponible: %s\n", boolToString(book.disponible));
			        printf("\n--------------------------\n");
				}
		        
		    	encontrado = 1;
		        break;
			}
		}
	}
	fclose(arc3);
	arc3 = NULL;

    if (!encontrado) {
        printf("No se encontro el  libro con el titulo ingresado.\n");
    }
    
    return book;
}

usuario agregarUsuario() {
	usuario client;
	printf("\nPor favor ingresar la identificaci%cn del cliente: ", 162);
	scanf("%d", &client.code);
	
	printf("Por favor ingresar el nombre del cliente: ");
	fflush(stdin);
	gets(client.name);

	client.is_valid = true;
	
	arc3 = fopen("usuario.txt", "a");
	
	if (arc3 == NULL ) {
		printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	} else {
		fwrite(&client, sizeof(client), 1, arc3);
		fclose(arc3);
		arc3 = NULL;
	}
	
	printf("Documento: %d\n", client.code);
	printf("Nombre: %s\n", client.name);
	return client;
}

usuario buscarUsuario(int code = NULL) {

    usuario client;
    int encontrado = 0;
	char confirmation;
	bool print = true;

	if(!code){
		printf("Por favor ingresar la identificaci%cn del cliente: ", 162);
		scanf("%d", &code);

		printf("Est%c seguro que la identificaci%cn %d est%c correcta? Si[S]  No[N]: ", 160, 162, code, 160);
		fflush(stdin);
		scanf("%c", &confirmation);
		confirmation = tuper(confirmation);
	} else {
		confirmation = 'S';
		print = false;
	}

	if(confirmation == 'S') {

		arc3 = fopen("usuario.txt", "rb");

		if (arc3 == NULL) {
			printf("Error al abrir el archivo\n");
		} else {
			while (fread(&client, sizeof(client), 1, arc3)) { 
				
				long pos = ftell(arc3);
				
				if (client.code == code) { 
				
				    if(print){
						printf("Documento: %d\n", client.code);
						printf("Nombre: %s\n", client.name);
					}
					
					encontrado = 1;
					break; 
				}
			}
			fclose(arc3);
			arc3 = NULL;

			if (!encontrado) {
				printf("No se encontr%c el cliente con el c%cdigo ingresado\n", 162, 162);
			}
		}

	} else {
		buscarUsuario();
	}

	return client;

}

void prestarLibro() {
	
	char titulo[MAX_TITULO];
	libro book;
	int code;
    
    book = buscarLibro(false);
    usuario user;
    
    printf("Ingrese la fecha del pr%cstamo (DD-MM-AAAA): ", 130);
	scanf("%d-%d-%d", &prestamo.date_start.day, prestamo.date_start.month, prestamo.date_start.year);
    
    if (book.is_valid) {
    	if (book.disponible) {
    		printf("Por favor ingresar la identificaci%cn del usuario: ", 162);
			scanf("%d", &code);
			user = buscarUsuario(code);
			printf("Documento: %d\n", user.code);
			printf("Nombre: %s\n", user.name);
		} else {
			printf("El libro con el t%ctulo ingresado no esta disponible.\n", 161);
		}
	}
	
    FILE *arch = fopen("prestamos.txt", "a");
    
    if(arch == NULL) {
    	printf("Error al crear el archivo.\n");
    	return;
	}
	
	fprintf(arch, "T%ctulo: %s", 161, prestamo.titulo);
	fprintf(arch, "Autor: %s", prestamo.autor);
	fprintf(arch, "Documento del prestatario: %d", prestamo.code);
	fprintf(arch, "Fecha de pr%cstamo", 130, prestamo.date_start);
	
	fclose(arch);
	
	printf("El pr%cstamo ha sido exitoso.\n", 130);
}

void devolverLibro() {
	char titulo[MAX_TITULO];
    Libro book;
    int code;
    
    book = buscarLibro(true);
    Usuario usua;
    
    printf("Ingrese la fecha de devolución (DD-MM-AAAA): ");
    scanf("%d-%d-%d", &prestamo.date_finish.day, &prestamo.date_finish.month, &prestamo.date_finish.year);
    
    if (book.is_valid) {
        printf("Por favor ingrese la identificaci%cn del usuario: ", 162);
        scanf("%d", &code);
        user = buscarUsuario(code);
        printf("Documento: %d\n", usua.code);
        printf("Nombre: %s\n", usua.name);
    } else {
        printf("El libro no tiene un pr%cstamo registrado.\n", 130);
        return;
    }
    
    FILE *arch = fopen("devoluciones.txt", "a");
    
    if (arch == NULL) {
        printf("Error al crear el archivo.\n");
        return;
    }
    
    fprintf(arch, "T%ctulo: %s\n", book.titulo);
    fprintf(arch, "Autor: %s\n", book.autor);
    fprintf(arch, "Documento del prestatario: %d\n", user.code);
    fprintf(arch, "Fecha de pr%cstamo: %d-%d-%d\n", 130, prestamo.date_start.day, prestamo.date_start.month, prestamo.date_start.year);
    fprintf(arch, "Fecha de devoluci%cn: %d-%d-%d\n", 162, prestamo.date_finish.day, prestamo.date_finish.month, prestamo.date_finish.year);
    
    fclose(arch);
    
    printf("La devoluci%cn del libro ha sido exitosa.\n", 162);
}


int main() {
    
    int op;
    
    do {
    	system("CLS");
    	op = menu();
    	
    	switch(op){
    		case 1:
    			agregarLibro();
    			break;
    		case 2:
    			mostrarBiblioteca();
    			break;
    		case 3:
    			buscarLibro(true);
    			break;
    		case 4:
    			prestarLibro();
    			break;
    		case 5:
    			devolverLibro();
    			break;
    		case 6:
    			agregarUsuario();
    			break;
    		case 7:
    			buscarUsuario();
    			break;
    		case 8:
    			printf("¡Gracias por usar el sistema de la biblioteca!\n");
    			break;
    		default:
    			printf("Ha ingresado una opcion incorrecta. Solo numeros del 1 al 8!!!\n\n");
    			break;
		}
		system("PAUSE");
	}while(op != 8);
	return 0;
	}
    

