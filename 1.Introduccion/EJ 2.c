#include <stdio.h>
#define PI 3.14159

int main(void){

	//Ejercicio A
	
	int lmay, lmen, PR, SR;
	printf("Ingrese el lado mayor y luego el lado menor del rectanglo:\n");
	scanf("%d %d", &lmay, &lmen);
	PR = (lmay * 2) + (lmen * 2);
	SR = lmay * lmen;
	printf("El perimetro es %d y la superficie es %d\n", PR, SR);
	
	//Ejercicio B
	
	int r, PC, SC;
	printf("Ingrese el radio:\n");
	scanf("%d", &r);
	PC = 2 * PI * r;
	SC = PI * r * r;
	printf("El perimetro es %d y la superficie es %d\n", PC, SC);
	
	//Ejercicio C
	
	int hs, valorHs, salario;
	printf("Ingrese las hs de trabajo diarias:\n");
	scanf("%i", &hs);
	printf("Ingrese el pago por hora trabajada:\n");
	scanf("%i", &valorHs);
	salario = hs * 30 *valorHs;
	printf("El salrio es: %i pesos", salario);
	
	//Ejercicio C Modificado
	
	int hs1, hs2, hs3, val1, val2, val3, sal1, sal2, sal3;
	printf("Ingrese las hs de trabajo diarias de cada trabajador en orden:\n");
	scanf("%d %d %d", &hs1, &hs2, &hs3);
	printf("Ingrese el pago por hora trabajada en el mismo orden:\n");
	scanf("%d %d %d", &val1, &val2, &val3);
	sal1 = hs1 * 30 *val1;
	sal2 = hs2 * 30 *val2;
	sal3 = hs3 * 30 *val3;
	printf("El salario del trabajador 1 es: %d pesos\n", sal1);
	printf("El salario del trabajador 2 es: %d pesos\n", sal2);
	printf("El salario del trabajador 3 es: %d pesos\n", sal3);
	
	return 0;
}
