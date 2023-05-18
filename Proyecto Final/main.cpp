// Libreria

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Definición de la estructura Producto
struct Producto {
    int codigo;
    char nombre[50];
    float precio;
    int stock;
};

// Función para agregar un producto
void agregarProducto(struct Producto *inventario, int *numProductos) {
    struct Producto nuevoProducto;
    
    printf("Ingrese el código del producto: ");
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

// Función para mostrar el inventario
void mostrarInventario(struct Producto *inventario, int numProductos) {
    printf("Inventario de la papelería:\n");
    
    for (int i = 0; i < numProductos; i++) {
        printf("Código: %d\n", inventario[i].codigo);
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
        printf("=== PAPERERÍA ===\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar inventario\n");
        printf("3. Salir\n");
        printf("Ingrese una opción: ");
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
                printf("Opción inválida. Inténtelo de nuevo.\n");
                break;
        }
    } while (opcion != 3);
    
    return 0;
}

