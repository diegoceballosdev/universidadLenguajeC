#include <stdio.h>
#include <math.h>

int ingresarNum (void);
int cantDivisores (int);
int determinarPrimo (int);
int cambioDeBase (int, int);
void mostrarNum (int, int, int);

int main() {
	
	int num1, num2, cantDiv, base;
	
	num1 = ingresarNum ();
	cantDiv = cantDivisores (num1);
	
	if( determinarPrimo(cantDiv) == 1)
		base = 2;
	else
		base = 9;
	num2 = cambioDeBase (num1, base);
	mostrarNum (num1, base, num2);
	return 0;
}

int ingresarNum (void){
	int X;
	float Y;
	do{
		printf("Ingrese un numero natural:\n");
		scanf("%f",&Y);
		X = (float) Y;
	} while(X<0 || X==0 || X != Y);
	return X;
}
int cantDivisores (int X){
	int pd, cont;
	cont = 0;
	for (pd=1; pd<=X/2; pd++){
		if (X % pd == 0)
			cont++;
	}
	return cont+1;
}
int determinarPrimo (int num){
	int pd;
	pd = 2;
	while (pd<=(num/2) && (num % pd != 0)){
		pd++;
	}
	if (pd>(num/2) && (num != 1))
		return 1;
	else
		return 0;
}

int cambioDeBase (int num, int base){
	int nuevoNum, resto, i;
	nuevoNum = 0;
	i = 0;
	do{
		resto = num % base;
		num /= base;
		nuevoNum += resto * pow(10,i);
		i++;
	} while(num != 0);
	return nuevoNum;
}	
void mostrarNum (int N1, int B, int N2){
	printf ("El numero %d expresado en base %d es: %d \n", N1, B, N2);
}
