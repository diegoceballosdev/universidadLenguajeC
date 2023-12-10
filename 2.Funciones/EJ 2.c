/*Ejercicio 2: Dados dos números naturales A y B, y un número natural Z 
generado al azar, si Z es par se solicita mostrar el resultado de A+B y 
si Z es impar se solicita mostrar el resultado de A*B.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(void){
	
	int A, B, Z;
	srand(time(NULL));	//SEMILLA
	printf("Ingrese A y B \n");
	scanf("%d", &A);
	scanf("%d", &B);
	Z = rand(); 
	printf("El num aleatorio Z es %d \n", Z);
	if(Z % 2 == 0)
	printf("La suma de %d y %d es: %d \n", A, B, A+B);
	else
	printf("El producto de %d y %d es: %d \n", A, B, A*B);

	return 0;
}
