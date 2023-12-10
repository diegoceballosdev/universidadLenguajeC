#include "TAD_Cliente.h"
#include <stdlib.h>

RCliente cargar_cliente(){
	RCliente nvo;
	fflush(stdin);
	printf("\nIngrese el Nombre del cliente: ");
	leeCad(nvo.nom, 20);
	fflush(stdin);
	printf("\nIngrese el Apellido del cliente: ");
	leeCad(nvo.ape, 20);
	fflush(stdin);
	printf("\nIngrese el DNI del cliente: ");
	scanf("%ld", & nvo.dni);
	printf("\nIngrese el Saldo del cliente: ");
	scanf("%f", & nvo.saldo);
	return nvo;
}
void mostrarcliente(RCliente cliente){
	printf("\nNombre y Apellido del cliente: %s %s\n", cliente.nom, cliente.ape);
	printf("\nDNI del cliente: %ld ----- Su saldo es: %f", cliente.dni, cliente.saldo);
}
void modifica(RCliente *cliente){
	RCliente nvo;
	nvo= *cliente;
	printf("\n---- Datos actuales del cliente ----");
	mostrarcliente(nvo);
	printf("\n---- Modificar todos los Datos actuales del cliente ----");
	nvo= cargar_cliente();
	*cliente= nvo;
}
long retorna_DNI(RCliente cliente){
	return cliente.dni;
}
float retornasaldo(RCliente cliente){
	return cliente.saldo;
}
int comparaDNI(RCliente cliente, long bus){
	if(cliente.dni==bus) return 1;
		else return 0;	
}
