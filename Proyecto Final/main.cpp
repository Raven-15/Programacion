#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functionsystem.h"

#define IN_REVIEW  1 //En revision
#define READY      2 //Listo
#define DELIVERED  3 //Entregado

FILE *arc1;
FILE *arc2;
FILE *arc3;


typedef struct {
	bool is_valid = false;
	int code;
	char name[40];
} person;

typedef struct {
	bool is_valid = false;
	char imei[15];
	char reference[35];
	char damage[200];
	char date_start[128];
	char date_finish[128] = "";
	int code_collaborator;
	int code_client;
	int status;
	char solution[200] = "";
} cellphone;

person registerCollaborator() {
	person collaborator;
	printf("\nPor favor ingresar la identificaci%cn del colaborador: ", 162);
	scanf("%d", &collaborator.code);
	
	printf("Por favor ingresar el nombre del colaborador: ");
	fflush(stdin);
	gets(collaborator.name);

	collaborator.is_valid = true;
	
	arc1 = fopen("collaborator.txt", "a");
	
	if (arc1 == NULL ) {
		printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	} else {
		fwrite(&collaborator, sizeof(collaborator), 1, arc1);
		fclose(arc1);
		arc1 = NULL;
	}
	
	printf("Documento: %d\n", collaborator.code);
	printf("Nombre: %s\n", collaborator.name);
	return collaborator;
}

person registerClient() {
	person client;
	printf("\nPor favor ingresar la identificaci%cn del cliente: ", 162);
	scanf("%d", &client.code);
	
	printf("Por favor ingresar el nombre del cliente: ");
	fflush(stdin);
	gets(client.name);

	client.is_valid = true;
	
	arc2 = fopen("client.txt", "a");
	
	if (arc2 == NULL ) {
		printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
	} else {
		fwrite(&client, sizeof(client), 1, arc2);
		fclose(arc2);
		arc2 = NULL;
	}
	
	printf("Documento: %d\n", client.code);
	printf("Nombre: %s\n", client.name);
	return client;
}

person searchClient(int code = NULL) {

    person client;
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
		arc2 = NULL;
		arc2 = fopen("client.txt", "rb");

		if (arc2 == NULL) {
			printf("Error al abrir el archivo\n");
		} else {
			while (fread(&client, sizeof(client), 1, arc2)) { // Lee cada registro del archivo
				
				
				if (client.code == code) { // Compara el c?digo del registro con el c?digo buscado
				    int pos = ftell(arc2);
					printf("El puntero se encuentra en la posicion: %d\n", pos);
					
					if(print){
						printf("Documento: %d\n", client.code);
						printf("Nombre: %s\n", client.name);
					}
					
					encontrado = 1;
					break; // Sale del bucle al encontrar el c?digo
				}
			}

			fclose(arc2);
			arc2 = NULL;

			if (!encontrado) {
				printf("No se encontr%c el cliente con el c%cdigo ingresado\n", 162, 162);
			}
		}

	} else {
		searchClient();
	}

	return client;

}

person searchCollaborator(int code = NULL) {

    person collaborator;
    int encontrado = 0;
	char confirmation;
	bool print = true;

	if(!code){
		printf("Por favor ingresar la identificaci%cn del colaborador: ", 162);
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
		arc2 = NULL;
		arc2 = fopen("collaborator.txt", "rb");

		if (arc2 == NULL) {
			printf("Error al abrir el archivo\n");
		} else {
			while (fread(&collaborator, sizeof(collaborator), 1, arc2)) { // Lee cada registro del archivo
				if (collaborator.code == code) { // Compara el c?digo del registro con el c?digo buscado
				    if(print){
						printf("Documento: %d\n", collaborator.code);
						printf("Nombre: %s\n", collaborator.name);
					}
					
					encontrado = 1;
					break; // Sale del bucle al encontrar el c?digo
				}
			}

			fclose(arc2);
			arc2 = NULL;

			if (!encontrado) {
				printf("No se encontr%c el colaborador con el c%cdigo ingresado\n", 162, 162);
			}
	
		}

	} else {
		searchCollaborator();
	}

	return collaborator;

}

void registerWarranty(){
	
	cellphone dataCellphone;
	person dataClient;
	person dataCollaborator;
	int flag;
	char confimation;

	time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    strftime(dataCellphone.date_start ,128,"%d/%m/%y %H:%M:%S",tlocal);
	
	fflush(stdin);
	printf("\nIngrese el imei del dispositivo: ");
	gets(dataCellphone.imei);

	fflush(stdin);
	printf("Ingrese la referencia del dispositivo: ");
	gets(dataCellphone.reference);

	fflush(stdin);
	printf("Ingrese la descripcion del da%co: ", 164);
	gets(dataCellphone.damage);

	dataClient = searchClient();

	if (!dataClient.is_valid) {
		flag = 1;

		do{
			printf("Desea registrar el cliente? Si[S]  No[N]: ");
			fflush(stdin);
			scanf("%c", &confimation);
			confimation = tuper(confimation);
			if (confimation == 'S') {
				flag = 0;
				dataClient = registerClient();

				if (!dataClient.is_valid) {
					printf("No se pudo registrar el cliente\n");
					system("PAUSE");
					return;
				} else {
					fflush(stdin);
					dataCellphone.code_client = dataClient.code;
				}
			} else if(confimation == 'N') {
				flag = 0;
				printf("No se registr%c el cliente\n", 162);
				system("PAUSE");
				return;
			} 
		} while (flag);

	} else {
		fflush(stdin);
		dataCellphone.code_client = dataClient.code;
	}

	dataCollaborator = searchCollaborator();

	if (!dataCollaborator.is_valid) {
		flag = 1;

		do{
			printf("Desea registrar el colaborador? Si[S]  No[N]: ");
			fflush(stdin);
			scanf("%c", &confimation);
			confimation = tuper(confimation);
			if (confimation == 'S') {
				flag = 0;
				dataCollaborator = registerCollaborator();
				if (!dataCollaborator.is_valid) {
					printf("No se pudo registrar el colaborador\n");
					system("PAUSE");
					return;
				} else {
					fflush(stdin);
					dataCellphone.code_collaborator = dataCollaborator.code;
				}
			} else if(confimation == 'N') {
				flag = 0;
				printf("No se registr%c el colaborador\n", 162);
				system("PAUSE");
				return;
			} 
		} while (flag);

	} else {
		fflush(stdin);
		dataCellphone.code_collaborator = dataCollaborator.code;
	}

	dataCellphone.status = IN_REVIEW;

	arc3 = fopen("registerCellphone.txt","a");
	if(arc3 == NULL) {
		printf("Error al abrir el archivo\n");
		system("PAUSE");
		return;
	} else {
		fwrite(&dataCellphone, sizeof(dataCellphone), 1, arc3);
        fclose(arc3);
	}
	
	
}

void searchWarranty() {

	cellphone dataWarranty;
	person dataCollaborator;
	person dataClient;
	char imei[15];
	bool wasfound = false;

	printf("\nIngrese el imei a consultar: ");
	fflush(stdin);
	gets(imei);
	arc3 = NULL;
	arc3 = fopen("registerCellphone.txt","rb");

	if(arc3 == NULL){
    	printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
    }

	while (!wasfound) {
		size_t leidos = fread(&dataWarranty, sizeof(dataWarranty), 1, arc3);
		if (leidos != 1) {
			if (feof(arc3)) {
				break; // Fin del archivo
			} else {
				perror("Error de lectura en el archivo");
				exit(EXIT_FAILURE);
			}
		}
		if (strcmp(imei, dataWarranty.imei) == 0) {
			wasfound = true;
		}
	}

	fclose(arc3);
	if (wasfound) {
		char* statusName = getStatusName(dataWarranty.status);
		dataCollaborator = searchCollaborator(dataWarranty.code_collaborator);
		dataClient =  searchClient(dataWarranty.code_client);

		printf("\nImei             : %s\n", dataWarranty.imei);
		printf("Referencia       : %s\n", dataWarranty.reference);
		printf("Da%co             : %s\n", 164, dataWarranty.damage);
		printf("Fecha de ingreso : %s\n", dataWarranty.date_start);
		printf("Fecha de entrega : %s\n", dataWarranty.date_finish);
		printf("Colaborador      : %s\n", dataCollaborator.name);
		printf("Cliente          : %s\n", dataClient.name);
		printf("Estado           : %s\n", statusName);
		printf("Resultado        : %s\n\n", dataWarranty.solution);

		free(statusName); // Liberar memoria asignada por malloc()
	} else {
		printf("No se encontr%c el valor!!!\n", 162);
	}

}

void updateWarranty() {

	cellphone dataWarranty;
	person dataCollaborator;
	person dataClient;
	char imei[15];
	bool wasfound = false;

	printf("\nIngrese el imei a consultar: ");
	fflush(stdin);
	gets(imei);
	
	arc3 = NULL;
	arc3 = fopen("registerCellphone.txt","r+b");

	if(arc3 == NULL){
    	printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
    }

	while (!wasfound) {
		size_t leidos = fread(&dataWarranty, sizeof(dataWarranty), 1, arc3);
		if (leidos != 1) {
			if (feof(arc3)) {
				break; // Fin del archivo
			} else {
				perror("Error de lectura en el archivo");
				exit(EXIT_FAILURE);
			}
		}
		if (strcmp(imei, dataWarranty.imei) == 0) {
			wasfound = true;
			printf("Ingrese nuevo estado\n");
			printf("1. En revision\n");
			printf("2. Listo\n");
			printf("3. Entregado\n");
			
			printf("Ingrese la opci%cn: ", 162);
			scanf("%d",&dataWarranty.status);
			
			if(dataWarranty.status == 3){
   				time_t tiempo = time(0);
				struct tm *tlocal = localtime(&tiempo);
				strftime(dataWarranty.date_finish, 128, "%d/%m/%y %H:%M:%S", tlocal);	
			}
			
			if(dataWarranty.status == 2){
				fflush(stdin);
   				printf("Redacte soluci%cn dada (Max 200 caracteres): ", 162);
				gets(dataWarranty.solution);
			}
			
			fseek(arc3, (long)-sizeof(dataWarranty), SEEK_CUR);
			fwrite(&dataWarranty, sizeof(dataWarranty), 1, arc3);
			fclose(arc3);
			printf("Cambio de estado exitoso!!!\n");
		}
	}

	if (wasfound) {
		char* statusName = getStatusName(dataWarranty.status);
		dataCollaborator = searchCollaborator(dataWarranty.code_collaborator);
		dataClient =  searchClient(dataWarranty.code_client);

		printf("\nImei             : %s\n", dataWarranty.imei);
		printf("Referencia       : %s\n", dataWarranty.reference);
		printf("Da%co             : %s\n", 164, dataWarranty.damage);
		printf("Fecha de ingreso : %s\n", dataWarranty.date_start);
		printf("Fecha de entrega : %s\n", dataWarranty.date_finish);
		printf("Colaborador      : %s\n", dataCollaborator.name);
		printf("Cliente          : %s\n", dataClient.name);
		printf("Estado           : %s\n", statusName);
		printf("Resultado        : %s\n\n", dataWarranty.solution);

		free(statusName); // Liberar memoria asignada por malloc()
	} else {
    	printf("Imei no encontrado\n");
	}

}

void deleteCollaborator(){
	
	int code, encontrado = 0;
	char confirmation;
	person collaborator;
	
	arc3 = NULL;
	arc3 = fopen("collaborator.txt", "r+");
	if(arc3 == NULL){
    	printf("Error al abrir el archivo\n");
		exit(EXIT_FAILURE);
    }
    
    FILE *temporal = fopen("archivo_temporal.txt", "a+");

    if(temporal == NULL){
    	printf("No se pudo crear el archivo temporal\n");
    	fclose(arc3);
		exit(EXIT_FAILURE);
    }
    
    printf("Por favor ingresar la identificaci%cn del colaborador: ", 162);
	scanf("%d", &code);

	printf("Est%c seguro que la identificaci%cn %d est%c correcta? Si[S]  No[N]: ", 160, 162, code, 160);
	fflush(stdin);
	scanf("%c", &confirmation);
	confirmation = tuper(confirmation);
    
    if(confirmation == 'S') {
		while (fread(&collaborator, sizeof(collaborator), 1, arc3)) { // Lee cada registro del archivo
				if (collaborator.code != code) {
					fwrite(&collaborator, sizeof(collaborator), 1, temporal);
				}else{
					encontrado = 1;
				}
		}
		fclose(arc3);
		fclose(temporal);
	}
	
	if(remove("collaborator.txt") == 0)   
		printf( "\nBorrado\n" );
	else
		printf( "\nNo se pudo Borrar el archivo\n" );
	
	if(rename("archivo_temporal.txt", "collaborator.txt") != 0){
		printf("No se pudo reemplazar el archivo original\n");
		exit(EXIT_FAILURE);	
	}
    
}
  
int menu()
{
    int option;
	printf("\n SERVICIO T%cCNICO\n\n", 144);
	printf("1. Ingresar Garant%ca\n", 161);
	printf("2. Consultar Garant%ca\n", 161);
	printf("3. Consultar Cliente \n");
	printf("4. Registrar Cliente \n");
	printf("5. Registrar Colaborador \n");
	printf("6. Actualizar estado de Garant%ca\n", 161);
	printf("7. Eliminar Colaborador \n");
	printf("8. SALIR\n");
	printf("ESCOJA UNA OPCION -->1 a 8<-- : ");
	scanf("%d", &option);
	
	return option;    
}

int main(int argc, char *argv[])
{
	int opc;

	do {
		system("CLS");
		opc=menu();

		switch (opc)
		{
			case 1:    
				registerWarranty();
				break;
		
			case 2: 
				searchWarranty();
				break;
		
			case 3:
				searchClient();
				break;
		
			case 4:
				registerClient();
				break;
		
			case 5:
				registerCollaborator();
				break;
		
			case 6:
			    updateWarranty();
				break;
				
			case 7:
			    deleteCollaborator();
				break;
		
			case 8:
				printf("Hasta pronto!!!\n");   
				break;
		
			default:
				printf("\nNo sea bestia, solo numeros del 1 al 8!!!\n\n");    
				break;
		}
		
		system("PAUSE");	
	} while (opc != 8);
	
	return 0;
}
