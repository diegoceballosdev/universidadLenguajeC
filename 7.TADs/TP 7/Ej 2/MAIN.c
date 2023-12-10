#include <stdio.h>
#include <stdlib.h>
#include "TAD_CUENTA.h"

int main (void){
	TRcuenta A, B, C;
	int op;
	long dni;
	
	A = cargarCuenta ();
	B = cargarCuenta ();
	C = cargarCuenta ();
	
	do{
		fflush(stdin);
		printf("\n Presione enter para mostrar el menu: ");
		getchar();
		system("cls");
		
		printf("\n 0[SALIR]");
		printf("\n 1[AGREGAR SALDO A UNA CUENTA]");
		printf("\n 2[RETIRAR DINERO DE UNA CUENTA]");
		printf("\n 3[MOSTRAR DATOS DE UNA CUENTA]");
		printf("\n");
		printf("\n SELECCIONE UNA OPCION: ");
		scanf("%d", &op);
		
		switch(op){
			case 0:
				printf("ADIOS");
				break;
			case 1:
				printf("\n Ingrese DNI del titular: ");
				scanf("%ld", &dni);
				if (retornaDNI(A) == dni)
					agregarSaldo(&A);
				else if (retornaDNI(B) == dni)
					agregarSaldo(&B);
				else if (retornaDNI(C) == dni)
					agregarSaldo(&C);
				else 
					printf("\n DNI no hallado");
				break;
			case 2:
				printf("\n Ingrese DNI del titular: ");
				scanf("%ld", &dni);
				if (retornaDNI(A) == dni)
					retirarSaldo(&A);
				else if (retornaDNI(B) == dni)
					retirarSaldo(&B);
				else if (retornaDNI(C) == dni)
					retirarSaldo(&C);
				else 
					printf("\n DNI no hallado");
				break;
			case 3:
				printf("\n Ingrese DNI del titular: ");
				scanf("%ld", &dni);
				if (retornaDNI(A) == dni)
					mostrarCuenta(A);
				else if (retornaDNI(B) == dni)
					mostrarCuenta(B);
				else if (retornaDNI(C) == dni)
					mostrarCuenta(C);
				else 
					printf("\n DNI no hallado");
				break;
			default:
				break;
		}
	} while(op != 0);
	
	return 0;
}
