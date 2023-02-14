#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    // Declaracion de variables y variables descuentos
    
    float porcentajeDescuentoSalud = 4;
    float porcentajeDescuentoPension = 4;
    float horasTrabajadas;
    float pagoPorHora;
    char nombre[30];
   
   	//Menu
   	printf("SALARIO EMPLEADO\n");
   	printf("\nNombre del empleado: ");
	scanf("%s",&nombre);
	printf("\nHoras trabajadas: ");
	scanf("%f",&horasTrabajadas);
	printf("\nValor hora trabajada: ");
	scanf("%f",&pagoPorHora);
   
    // Realizar cálculos
    float salarioBruto = pagoPorHora * horasTrabajadas;
   
    // Calcular descuentos
    float descuentoSalud = (porcentajeDescuentoSalud * salarioBruto) / 100;
    float descuentoPension = (porcentajeDescuentoPension * salarioBruto) / 100;
    
	// Total de deducciones
    float totalDeducciones = descuentoSalud + descuentoPension;
    
	// Restamos al salario bruto
    float sueldoNeto = salarioBruto - totalDeducciones;
    
	// Imprimir los valores
	printf("\nEmpleado: %s", nombre);
	printf("\nHoras Trabajadas: %f", horasTrabajadas);
    printf("\nValor hora trabajada: %f", pagoPorHora);
    printf("\nTOTAL SALARIO: %f", salarioBruto);
    printf("\nDescuento salud: %f", descuentoSalud);
    printf("\nDescuento pension: %f", descuentoPension);
    printf("\nTotal deducciones: %f", totalDeducciones);
    printf("\nSALARIO NETO: %f", sueldoNeto);
        
	return 0;
}
