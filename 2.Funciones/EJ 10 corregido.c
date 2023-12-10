#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumDivDeNum (int);
int determinarSiNoEsDeficiente (int, int);

int main() {
	
	int A, B, N, num, i, sumaDiv;
	srand(time(NULL));
	
	printf("Ingrese la cantidad de numeros de la lista: \n");
	scanf("%d", &N);
	
	printf("Ingrese el valor de A y luego de B para el rango de numeros:\n");
	scanf("%d %d", &A, &B);
	
	for (i=1; i<=N; i++){
		num = rand() % (B - A + 1) + A;
		printf("Se genero el numero: %d \n", num);
		
		sumaDiv = sumDivDeNum (num);
		if (determinarSiNoEsDeficiente (num, sumaDiv))
			printf("El numero %d NO es deficiente\n", num);
	}

	return 0;
}


int sumDivDeNum (int num){
	int sum, i;
	sum= 0;
	for (i=1; i<=(num/2); i++){
		if (num % i == 0)
		sum += i;
	}
	return sum;
}
int determinarSiNoEsDeficiente (int num, int sumDiv){
	if (sumDiv >= num)
		return 1;
	else
		return 0;
}
