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
		printf("\n 4[MOSTRAR CUENTAS ORDENADAS ALFABETICAMENTE]");
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
			case 4:
				if (comparaNombre(A,B)==-1){
					if (comparaNombre(B,C)==-1){
						mostrarOrdAlf (A, B, C);
					}
					else{ 	//cuando B<C
						mostrarOrdAlf (A, C, B);
					}
				}
				else if (comparaNombre(A,B)==1){
					if (comparaNombre(A,C)==-1){
						mostrarOrdAlf (B, A, C);
					}
					else{	//cuando A<C
						mostrarOrdAlf (B, C, A);
					}
				}
				else if (comparaNombre(C,A)==-1){
					if (comparaNombre(A,B)==-1){
						mostrarOrdAlf (C, A, B);
					}
					else{	//cuando A<B
						mostrarOrdAlf (C, B, A);
					}
				}
				break;
			default:
				break;
		}
	} while(op != 0);
	
	return 0;
}
