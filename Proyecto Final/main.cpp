// Libreria

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Definici�n de la estructura Producto
struct Producto {
    int codigo;
    char nombre[50];
    float precio;
    int stock;
};

// Funci�n para agregar un producto
void agregarProducto(struct Producto *inventario, int *numProductos) {
    struct Producto nuevoProducto;
    
    printf("Ingrese el c�digo del producto: ");
    scanf("%d", &nuevoProducto.codigo);
    
    printf("Ingrese el nombre del producto: ");
    scanf("%s", nuevoProducto.nombre);
    
    printf("Ingrese el precio del producto: ");
    scanf("%f", &nuevoProducto.precio);
    
    printf("Ingrese el stock del producto: ");
    scanf("%d", &nuevoProducto.stock);
    
    inventario[*numProductos] = nuevoProducto;
    (*numProductos)++;
    
    printf("Producto agregado correctamente.\n");
}

// Funci�n para mostrar el inventario
void mostrarInventario(struct Producto *inventario, int numProductos) {
    printf("Inventario de la papeler�a:\n");
    
    for (int i = 0; i < numProductos; i++) {
        printf("C�digo: %d\n", inventario[i].codigo);
        printf("Nombre: %s\n", inventario[i].nombre);
        printf("Precio: %.2f\n", inventario[i].precio);
        printf("Stock: %d\n", inventario[i].stock);
        printf("------------------------------\n");
    }
}

int main() {
    struct Producto inventario[100];
    int numProductos = 0;
    int opcion;
    
    do {
        printf("=== PAPERER�A ===\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Salir\n");
        printf("Ingrese una opci�n: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                agregarProducto(inventario, &numProductos);
                break;
            case 2:
                mostrarInventario(inventario, numProductos);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opci�n inv�lida. Int�ntelo de nuevo.\n");
                break;
        }
    } while (opcion != 3);
    
    return 0;
}

