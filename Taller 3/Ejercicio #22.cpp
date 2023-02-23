//Ejercicio #22


#include <stdio.h>

int main (){
	int n, di, conta = 0;
	printf("Angelica Escriba un numero entero: ");
	scanf("%d", &n);
	
	while (n!=0){
		di = n % 10;
		if (di == 1){
			conta ++;
		}
		n /= 10;
	}
	printf("El numero ingresado tiene el digito 1 %d veces.\n", conta);
	
	return 0;
}
