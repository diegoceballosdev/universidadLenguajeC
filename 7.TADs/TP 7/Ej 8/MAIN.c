#include <stdio.h>
#include <stdlib.h>
#include "TAD_LISTA_CUENTAS.h"

int main (void){
	TRlista L;
	int op;
	
	inicializarLista (&L);
	L = cargarLista();
	
	do{
		fflush(stdin);
		printf("\n PRESIONE ENTER PARA MOSTRAR EL MENU");
		getchar();
		system("cls");
		
		printf("\n 0[SALIR]");
		printf("\n 1[ELIMINAR UNA CUENTA]");
		printf("\n 2[AGREGAR CUENTA]");
		printf("\n 3[MOSTRAR CUENTA/AS DE UN TITULAR]");
		printf("\n 4[DEPOSITAR O EXTRAER]");
		printf("\n 5[MOSTRAR CUENTAS SIN SALDO]");
		printf("\n");
		printf("\n SELECCIONE UNA OPCION: ");
		scanf("%d", &op);
	
	switch(op){
		case 0:
			printf("\n ADIOS");
			break;
		case 1:
			if (listaVacia(L)==1)
				printf("\n Lista vacia");
			else
				eliminarCuentaDeLista(&L);
			break;
		case 2:
			if (listaVacia(L)==1)
				printf("\n Lista vacia");
			else
				agregarCuenta(&L);
			break;
		case 3:
			if (listaVacia(L)==1)
				printf("\n Lista vacia");
			else
				mostrarPorDNI(L);
			break;
		case 4:
			if (listaVacia(L)==1)
				printf("\n Lista vacia");
			else
				movimientoCuenta(&L);
			break;
		case 5:
			//completar
			//completar
			break;
		default:
			printf("\n INGRESE UNA OPCION VALIDA");
			break;
	}
	
	}while(op!=0);

	return 0;
}
