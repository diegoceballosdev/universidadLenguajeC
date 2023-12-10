#include<stdio.h>
#include "TADregistro.h"

Reg_per cargar_reg(){
	Reg_per aux;
	printf("\nIngrese apellido y nombre: ");
	fflush(stdin);
	leecad(aux.nomyape, n);
	printf("\nIngrese DNI: ");
	scanf("%ld",&aux.dni);
	printf("\nIngrese condicion: (1-Regular o 2-Libre): ");
	scanf("%hd",&aux.cond);
	return aux;
}
	
long retorna_dni(Reg_per aux){
	return aux.dni;
}

short retorna_cond(Reg_per aux){
	return aux.cond;
}
	
void mostrar_reg(Reg_per aux){
	printf("\nApellido y nombre son: %s",aux.nomyape);
	printf("\nDNI es: %ld: ",aux.dni);
	if(aux.cond==1){
		printf("\nCondicion: Regular");
	}
	else{
		printf("\nCondicion: Libre");
	}
	printf("\n");
}
