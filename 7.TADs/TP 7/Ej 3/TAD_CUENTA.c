#include <stdio.h>
#include "TAD_CUENTA.h"

/****** CARGAR ******/

TRcuenta cargarCuenta (){
	TRcuenta aux;
	printf("\n INGRESE DATOS DE UNA CUENTA:");
	printf("\n Ingrese DNI: ");
	scanf("%ld", &aux.DNI);
	fflush(stdin);
	printf("\n Ingrese Apellido y Nombre: ");
	ingresarCadena(aux.ApeNom, MAXCAD);
	printf("\n Ingrese nro de cuenta: ");
	scanf("%d", &aux.cuenta);
	printf("\n Ingrese saldo: ");
	scanf("%d", &aux.saldo);
	return aux;
}

/****** MOSTRAR ******/
	
void mostrarCuenta (TRcuenta C){
	printf("\n DNI: %ld", C.DNI);
	printf("\n Nro de cuenta: %d", C.cuenta);
	printf("\n Saldo: %d", C.saldo);
}

/****** RETORNAR CAMPO ******/
	
int retornaSaldo (TRcuenta C){
	return C.saldo;
}

long retornaDNI (TRcuenta C){
	return C.DNI;
}

/****** MODIFICAR SALDO ******/	

void modificarSaldo (TRcuenta *C, int importe){
	C->saldo = importe;
	printf("\n Nuevo saldo: %d", C->saldo);
}

void agregarSaldo (TRcuenta *C){
	int imp;
	printf("\n Saldo actual: %d", C->saldo);
	printf("\n Ingrese el importe que desea agregar a la cuenta: ");
	scanf("%d", &imp);
	C->saldo += imp;
	printf("\n Nuevo saldo: %d", C->saldo);
}

void retirarSaldo (TRcuenta *C){
	int imp;
	printf("\n Saldo actual: %d", C->saldo);
	printf("\n Ingrese el importe que desea retirar de la cuenta: ");
	scanf("%d", &imp);
	C->saldo -= imp;
	printf("\n Nuevo saldo: %d", C->saldo);
}
/****** CADENAS ******/

int comparaNombre (TRcuenta X, TRcuenta Y){
	return comparaCadena(X.ApeNom, Y.ApeNom);
}

void mostrarOrdAlf (TRcuenta X, TRcuenta Y, TRcuenta Z){
	printf("1°: %s - 2°: %s - 3°: %s", X.ApeNom, Y.ApeNom, Z.ApeNom);
}

	
	
	
	
	
	
	
	
	
