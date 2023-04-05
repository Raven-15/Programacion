//Angelica Punto #5

#include <stdio.h>

int main() {
  int vector[20];
  int n_buscado, posicion = 0; // 0 indica que el numero buscado no está en el vector
  
  printf("Escriba 20 numeros enteros:\n");
  
  for(int i = 0; i < 20; i++) {
    scanf("%d", &vector[i]);
  }
  
  printf("Escriba el numero que deseas buscar: ");
  scanf("%d", &n_buscado);
  
  for(int i = 0; i < 20; i++) {
    if(vector[i] == n_buscado) {
      posicion = i;
      break;
    }
  }
  
  if(posicion != 0) {
    printf("El numero %d se encuentra en la posicion %d del vector: ", n_buscado, posicion);
  } else {
    printf("El numero %d no se encuentra en el vector: ", n_buscado);
  }
  
  return 0;
}

