/*Ejemplo 1: Realizar la especificación e implementación de un TAD que
manipula una estructura de registro de Cuenta Bancaria de quien se almacena
los siguientes datos:
-Nro. de Documento del Titular
- Nro. de Cuenta.
- Saldo
Y realiza las siguientes operaciones:
- Cargar los datos de una cuenta
- Mostrar los datos de una cuenta
- Retornar el saldo de la cuenta.
- Retornar el Nro. de Documento
-Modificar el saldo dado un importe.
Realizar un programa que utilice el TAD creado para que, dada 1 Cuenta,
mediante un menú el usuario pueda, ingresando el DNI del titular:
-Agregar saldo a una cuenta.
- Retirar dinero de una cuenta (Si es que tiene saldo)
- Mostrar los datos de una cuenta.

*/
#include<stdio.h>
#include <windows.h>
#include "TAD_CUENTA.h"

int menu(void);

int main(){
	TCuenta cuenta;
	long doc;
	int montoa,op;
	
	cuenta=cargarCuenta();	
	
	do{
		fflush(stdin);
		printf("\n\n Presione Enter para mostrar MENU de Opciones");
		getchar();
		system("cls");
		op=menu();
		switch (op){
		case 1: 
			printf("\nAgregar saldo a una cuenta");
			printf("\nIngrese el DNI del titular de la cuenta: ");
			scanf("%ld",&doc);
			if(retornaDni(cuenta) == doc){
				printf("\nIngrese el monto a agregar: ");
				scanf("%d",&montoa);
				modificarSaldo(&cuenta,montoa);
			 } 
			 else 
			   printf("\nNo exise cuenta con DNI ingresado ");
			break;
		case 2: 
			printf("\nRetirar dinero de una cuenta");
			printf("\nIngrese el DNI del titular de la cuenta a retirar: ");
			scanf("%ld",&doc);
			if (retornaDni(cuenta)==doc){
				printf("\nIngrese monto a retirar: ");
				scanf("%ld",&montoa);			  
				if (retornaSaldo(cuenta)>=montoa){
					montoa=montoa*-1;
					modificarSaldo(&cuenta,montoa);
					//printf("\nDatos actualizados: ");
					//MostrarCuenta(cuenta);}
				}
				else printf("\nNo tiene saldo suficiente para retirar: ");
			}
			else 
		        	printf("\nNo exise cuenta con DNI ingresado ");
			
			break;
		case 3: 
			printf("\nIngrese el DNI del titular de la cuenta a mostrar: ");
			scanf("%ld",&doc);
			if (retornaDni(cuenta)==doc)
				mostrarCuenta(cuenta);
			else
				printf("\nNo exise cuenta con DNI ingresado ");
		     break;
		case 0: printf("\nSaliendo...");
		     break;
		default: printf("Opcion incorrecta, elija otra opcion");	
		}
	}
	while(op!=0);	
	return 0;
}
	
int menu(){
	int op;
	printf("\n MENU\n");
	printf("1- Agregar Saldo a una cuenta\n");
	printf("2- Retirar saldo de una cuenta\n");
	printf("3- Mostrar los datos de una cuenta\n");
	printf("0- Salir\n");
	printf("Elija una opcion: ");
	scanf("%d",&op);
	return op;
}
