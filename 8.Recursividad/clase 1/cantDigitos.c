/* Ejemplo 1: Mostrar la cantidad de dígitos de un numero entero positivo*/

#include <stdio.h>

int cantdig(int);

int main(int argc, char *argv[]) {
	int nro;
	
	printf("\n Ingrese un nro: ");
	scanf("%d",&nro);	
	printf("el nro tiene %d digitos",cantdig(nro));
	return 0;
}

int cantdig(int num)
{
	if(num>0)
		return(1+cantdig(num/10));	
	else
	   return 0;
}


