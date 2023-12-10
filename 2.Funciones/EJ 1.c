/*
Ejercicio 1: Dados un número real A, se solicita calcular y mostrar:
a) El Seno de A.
b) El logaritmo de A.
c) El valor absoluto de A.
*/

#include <stdio.h>
#include<math.h>
#include<stdlib.h>



int main(void) {
	
	//Ejercicio A. Calcular seno
	
	double x;
	printf("Ingrese valor de x en grados \n");
	scanf("%lf", &x);
	x=x*(3.14159/180);
	printf("El valor del seno en radianes es: %lf \n", sin(x));
	
	
	//Ejercicio B. Calcular logaritmo
	
	double y;
	printf("Ingrese el argumento del log: \n");
	scanf("%lf", &y);
	printf("El logaritmo de %lf es: %lf \n", y, log(y));
	
	
	//Ejercicio C. Calcular abs
	
	int z;
	printf("ingrese el numero: \n");
	scanf("%d", &z);
	printf("el absoluto de %d es : %d", z, abs(z));
	
	return 0;
}

