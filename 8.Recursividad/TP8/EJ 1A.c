/*Mostrar los d�gitos de un n�mero natural X de derecha a izquierda. 
Realizar la traza para X= 45673.*/

#include <stdio.h>

void mostrarDigA(int X);
void mostrarDigB(int X);

int main(int argc, char *argv[]) {
	
	int num;
	printf("INGRESE UN NUMERO NATURAL: ");
	scanf("%d", &num);
	
	printf(" \n DIGITOS DE DERECHA A IZQUIERDA \n");
	mostrarDigA(num);
	
	printf(" \n DIGITOS DE IZQUIERDA A DERECHA\n ");
	mostrarDigB(num);
	
	return 0;
}

void mostrarDigA(int X){
	
	if (X!=0){
		printf ("\n Digito: %d \n", X%10);
		mostrarDigA(X/10);
	}
}

//�C�mo se modificar�a el programa si se desea 
//mostrar los d�gitos de izquierda a derecha? :
	
void mostrarDigB(int X){
	
	if (X!=0){
		mostrarDigB(X/10);
		printf ("\n Digito: %d \n", X%10);
	}
}
