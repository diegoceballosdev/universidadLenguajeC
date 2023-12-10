#include<stdio.h>
#include "TAD_CUENTA.h"


TCuenta cargarCuenta(){
	TCuenta nvo;
	
	printf("\nIngresar datos de la cuenta \n");
	printf("\nIngrese DNI: ");
	scanf("%ld", &nvo.dni);
	printf("\nIngrese Nro de cuenta: ");
	scanf("%d", &nvo.nro);
	nvo.saldo= 0;	
	return nvo;
	
}
void mostrarCuenta(TCuenta A){	
	printf("\nDNI: %ld",  A.dni);
	printf("\nNro de Cuenta: %d",  A.nro);
	printf("\nSaldo: %d",  A.saldo);	
}

int retornaSaldo(TCuenta A){
	return A.saldo;
	
}
long retornaDni(TCuenta A){
	return A.dni;
	
}
void modificarSaldo(TCuenta *A,int monto){
	A->saldo=A->saldo+monto;	
}
