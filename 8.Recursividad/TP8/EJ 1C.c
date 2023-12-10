/*Obtener el Factorial de un número natural X. Realizar la traza para X= 8.*/

#include <stdio.h>

int factorial (int X);

int main(int argc, char *argv[]) {
	
	int num;
	
	printf("\n Ingrese un numero entero positivo: ");
	scanf("%d", &num);
	
	printf("\n El factorial de %d es: %d", num, factorial(num) );
	
	return 0;
}

int factorial (int X){
	
	if (X == 0)
		return 1;
	else 
		return X * factorial (X-1);
		
}
