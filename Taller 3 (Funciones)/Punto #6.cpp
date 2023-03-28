//Punto #6

#include <stdio.h>

int entero(int numero){
	if(numero >= 0 && numero <= 255){
		return 0;
	}else{
		return 1;
	}
}
int main(){
	int numero;
	
	printf("Ingrese un numero: ");
	scanf("%d", &numero);
	
	int resultado = entero(numero);
	
	if(resultado == 0){
    	printf("%d esta dentro del rango.\n", numero);
    }else{
	    printf("%d esta fuera del rango.\n", numero);
    }
     
	return 0;
	
}

//int validar_rango(int numero) {
    //if (numero < 0 || numero > 255) {
       // return 1;
   // } else {
       //// return 0;
   // }
    
//}
