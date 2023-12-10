#include <stdio.h>

int main() {
	int i, N, X, A, B, contA, contB;
	contA = 0, contB = 0;
	printf("Ingrese la cantidad de numeros de la lista: \n");
	scanf("%d", &N);
	printf("Ingrese el valor A: \n");
	scanf("%d", &A);
	printf("Ingrese el valor B: \n");
	scanf("%d", &B);
	
	for (i=1; i<=N; i++){
		
		printf("Ingrese el %d° numero: \n", i);
		scanf("%d", &X);
		
		if (X % A == 0 && X % B != 0)
			contA++;
		if (X % B == 0 && X % A != 0)
			contB++;
	}
	
	printf("Se ingresaron %d numeros que son multiplos solo de A \n", contA);
	printf("Se ingresaron %d numeros que son multiplos solo de B \n", contB);
	return 0;
}

