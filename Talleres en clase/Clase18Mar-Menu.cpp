//MENU Angelica

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int leer_datos(int vector[]){
	int i;
	for (i= 0; i < 10; i ++){
	printf("Ingrese 10 numeros enteros: ");
	  scanf("%d", &vector[i]);
	
   }
}
int sumar_datos(int vector[]){
	int i;
	int suma = 0;
	for(i = 0; i < 10;i ++){
		suma += vector[i];
	}
	printf("La suma de los datos es: %d\n", suma);
}	
 
int cuadrado_datos(int vector[]){
	printf("los cuadrados de los datos son:\n");
	int i;
	for(i = 0; i < 10; i++){
		int cuadrado = pow(vector[i], 2);
		printf("%d ", cuadrado);
	}
	printf("\n");
 }
 
 
float promedio_datos(int vector1[]){
	printf("Los promedios de cada pareja de datos son: ");
	int i;
	for(i = 0; i < 10; i++){
		float promedio = (vector1[i] + pow (vector1[i], 2)) / 2.0;
		printf("El promedio de %d y su cuadrado %d es: %f\n", vector1 [i], (int)pow(vector1[i], 2), promedio);
		}
	}

int menu(){
    int opcion;
    printf ("             MENU\n");
    printf ("\n");
    printf ("1- Leer datos\n");
    printf ("2- sumar datos\n");
    printf ("3- Cuadrado de los datos\n");
    printf ("4- Promedio de los datos\n");
    printf ("5- Salir\n");
    
    printf("   Ingrese una opcion: ");
    scanf ("%d", &opcion);
    
    return opcion;
    
}
int main(){
	int vector[10];
	int opcion;
	
	do{
		system("CLS");
		opcion = menu();
		
		switch(opcion){
			
	    case 1:
  		    leer_datos(vector);
            break;
        case 2:
    	    sumar_datos(vector);
            break;
        case 3:
            cuadrado_datos(vector);
            break;
        case 4:
            promedio_datos(vector);
            break;
        case 5:
   	        printf("SALIR!\n");
   	        break;
   	    default:
   		    printf("Opcion Invalida,intente de nuevo.\n");
   		    break;
		}
		
		system("PAUSE");
	}while (opcion != 5);
	return 0;
}
  
   
  
 

