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

	/* compara el nro de cuenta de 2 registros*/
int compararCuenta(TCuenta A, TCuenta B){ 
	if(A.nro>B.nro) return 1;
	else if(A.nro<B.nro) return -1;
	else return 0;
	
	
}
int retornaSaldo(TCuenta A){
	return A.saldo;
	
}
Tdni retornaDni(TCuenta A){
	return A.dni;
	
}
void modificarSaldo(TCuenta *A,int monto){
	A->saldo=A->saldo+monto;	
}
	
