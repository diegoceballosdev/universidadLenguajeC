/*Dada la siguiente definición recursiva:*/
/*Formule el módulo recursivo y la traza para el cálculo del resto (22,5).*/

#include <stdio.h>

int resto (int , int );

int main(void) {
	
	int num1, num2;
	printf("\nIngrese un numero: ");
	scanf("%d", &num1);
	printf("\nIngrese otro numero: ");
	scanf("%d", &num2);
	
	printf("\nEl resto de %d en %d es: %d", num1, num2, resto (num1, num2));
	
	return 0;
}

/******** MODULO RECURSIVO **************/

int resto (int X, int Y){
	if (X < Y)
		return X;
	else
		return resto (X-Y, Y);
	
}
