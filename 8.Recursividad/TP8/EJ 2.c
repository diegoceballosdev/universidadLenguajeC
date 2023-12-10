/*Realice la traza del siguiente programa con los valores 100, luego con 27. 
Elabore una consigna indicando qué hace el programa.*/

#include <stdio.h>

int c_d(int);

int main(int argc, char *argv[]) {
	int x;
	printf("\nIngrese un numero: ");
	scanf("%d", &x);
	printf("\n Resultado= %d", c_d(x));
	return 0;
}
int c_d(int num){
	if (num==0) 
		return 0;
	else {
		num=num/10;
		return 1 + c_d(num); 
	}
}

/* El programa calcula la cantidad de digitos de un numero dado. */
