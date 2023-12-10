#include <stdio.h>

int main() {
	
	int A, B, C;
	do{
		printf("Ingrese el valor de los angulos A, B y C del triangulo:\n");
		scanf("%d %d %d", &A, &B, &C);
	}while((A+B+C!=180) || A<=0 || B<=0 || C<=0);
	
	if (A==90 || B==90 || C==90)
		printf("Es un triangulo recto");
	else if (A<90 && B<90 && C<90)
		printf("Es un triangulo acutangulo");
	else
		printf("Es un triangulo obtusangulo");

	return 0;
}
