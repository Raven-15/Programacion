//Punto #3

#include <stdio.h>

char _ascii(int num){
	return(char) num;
}

int main(){
	int num = 204;
	char c = _ascii(num);
	printf("El numero %d en ASCII es el caracter '%c'\n", num, c);
	return 0;
}
