#ifndef TAD_CLIENTE_H
#define TAD_CLIENTE_H
#include "TAD_Cadena.h"

typedef struct{
	TCadena ape, nom;
	long dni;
	float saldo;
}RCliente;

RCliente cargar_cliente();
void mostrarcliente(RCliente);
void modifica(RCliente *cliente);
long retorna_DNI(RCliente);
float retornasaldo(RCliente);
int comparaDNI(RCliente, long);

#endif
