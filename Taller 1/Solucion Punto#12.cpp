#include <stdio.h>
#include <stdlib.h>

int main (){
	
	int kmRecorridos, kmGalon, valorgalonCorriente=10750, valorgalonExtra=15000;
	float galonesNec, totalCorriente, totalExtra;
	
	printf("Ingrese los km que quiere recorrer:");
	scanf("%i",&kmRecorridos);

	printf("Ingrese cuantos galones por km consume su carro:");
	scanf("%i",&kmGalon);
	
	galonesNec=kmRecorridos/kmGalon;
	totalCorriente=galonesNec*valorgalonCorriente;
	totalExtra=galonesNec*valorgalonExtra;
	
	printf("El total de galones necesarios para su recorrido es: %f \n", galonesNec);
	printf("El valor de la gasolina corriente necesaria para tu viaje es de: %f \n", totalCorriente);
	printf("El valor de la gasolina extra necesaria para tu viaje es de: %f \n", totalExtra);
}
