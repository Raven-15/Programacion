//Punto #4

#include <stdio.h>

int _ascii(char c){
	return (int) c;
}
int main(){
	char c = '@';
	int numero = _ascii(c);
	printf("El caracter '%c' en ASCII es el numero %d\n",c, numero);
	return 0;
}
