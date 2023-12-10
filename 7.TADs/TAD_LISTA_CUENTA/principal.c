/**Realizar la especificacion e implementacion de un TAD que manipule Arreglo de Registros
que permita cargar una lista de N Cuentas bancarias de las cuales
se tiene la siguiente información: DNI, Nro de Cuenta y Saldo
Luego implementar un programa que a traves de un menú permita Mostrar la lista y
Ordenar la lista. 
-----
Mostrar los datos de una cuenta dado DNI del titular*/

#include <stdio.h>
#include "TAD_LISTA.h"

int main(){
	TLista X;
	int Res;
	X=Cargar_Lista();
	/* int op;*/
	do {
		printf("\nIngrese 0 [Salir]; 1 [Ordenar]; 2 [Mostrar] ; 3 [Mostrar una Cuenta]");
		scanf("%d", &Res);
		/*op=menu();
		switch(op);*/
		switch(Res){
		case 0: printf("\nSalir del programa"); break;
		case 1: Ordenar_lista(&X); break;
		case 2: Mostrar_lista(X); break;
		case 3: Mostrar_Cuenta(X); break;
		default: printf("\nValor no valido"); }
	} while(Res!=0);
	return 0;
}

	/*int menu(void){
	int Res;
	printf("\nIngrese 0 [Salir];
	printf("\nIngrese 1 [Ordenar] ");
	printf("\nIngrese 2 [Mostrar] ");
	printf("\nIngrese 3 [Mostrar una cuenta] ");
	scanf("%d", &Res);
}
*/
