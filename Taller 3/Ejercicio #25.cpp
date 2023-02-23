//Ejercicio #25

#include <stdio.h>

int main(){
	int num, suma = 0; 
	int cont = 0;
	printf("Ingrese un numero entero: ");
	scanf("%d", &num);
	
	while(num>0){
		int di = num % 10;
		suma += di;
		cont++;
		num /= 10;
	}
	if (cont == 0){
		printf("El numero ingresado es 0\n");
		return 0;
	}
	
	int prom = suma/cont;
	print("El promedio entero de los digitos del numero ingresado es:%d\n", prom);
	return 0;
}
