#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int cantDig (int);
int digMasSignificativo (int);
int determinarPrimo (int);
	
int main(int argc, char *argv[]) {

	int N, X, i, contDig;

	printf("Ingrese la cantidad de numeros de la lista:\n");
	scanf("%d",&N);
	
	for (i = 1; i <= N; i++){
		printf("Ingrese el %i° numero de la lista:\n", i);
		scanf("%d",&X);
		contDig = cantDig(X);
		printf("Su cantidad de digitos es %d \n",contDig);
		if ( determinarPrimo(contDig) == 1)
			printf ("La cant de dig del num ingresado es un num primo, entonces hacemos %d^%d = %lf \n", X, digMasSignificativo(X), pow(X, digMasSignificativo(X)));
		else
			printf ("La cant de dig del num ingresado NO es un num primo, entonces hacemos raiz cuadrada de %d = %lf \n", X, sqrt(X));
	}

	return 0;
}

int cantDig (int X){
	int contDigitos;
	contDigitos = 0;
	X = abs(X);
	while(X != 0){
		X = X/10;
		contDigitos++;
	}
	return contDigitos;
}
int digMasSignificativo (int X){
	int dig;
	X = abs(X);
	while(X != 0){
		dig = X%10;
		X = X/10;
	}
	return dig;
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
