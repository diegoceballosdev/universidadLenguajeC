/*Se necesita un programa en C, que simule el tiempo que esperan dos clientes 
A y B, para realizar un trámite en el banco. El programa deberá mostrar cual es 
cliente que será atendido primero.El tiempo de espera a cada cliente se asigna 
de forma aleatoria, siendo un número natural en el rango [1,30].

Nota: Si el rango es ingresado por el usuario, como se modificaría la solución 
original.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void){
	
	int A, B, RI, RF;
	srand(time(NULL));
	printf("Ingrese RI y RF: \n");
	scanf("%d", &RI);
	scanf("%d", &RF);
	do{ 
		A = rand()%(RF-RI+1)+RI;
		B = rand()%(RF-RI+1)+RI;
	} while(A==B);
	printf("A es %d y B es %d \n", A, B);
	if(A < B)
		printf("El cliente A sera atendida primero");
	if(A > B)
		printf("El cliente B sera atendida primero");
	
	return 0;
}
