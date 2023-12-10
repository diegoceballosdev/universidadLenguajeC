#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void numDeficiente(int);

int main() {
	
	int i, N, A, B, X;
	srand(time(NULL));
	
	printf("Ingrese la cantidad de numeros de la lista: \n");
	scanf("%d", &N);
	
	printf("Ingrese el valor de A y luego de B para el rango de numeros:\n");
	scanf("%d %d", &A, &B);
	
	for (i=1; i<=N; i++){
		X = rand() % (B - A + 1) + A;
		numDeficiente(X);
	};
	
	return 0;
}

void numDeficiente(int X){
	int PD, sumDiv = 0;
	
	for(PD=1; PD<=(X/2); PD++){
		if (X % PD == 0)
			sumDiv+=PD;
	};
	
	if(X <= sumDiv)
		printf("El numero aleatorio %d no es un numero deficiente \n", X);
}

/*  La consigna no indica que los numeros generados deban ser mostrados.
	Por lo tanto solo se muestran aquellos que cumplen con lo solicitado.*/
