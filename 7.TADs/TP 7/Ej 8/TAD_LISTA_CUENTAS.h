#ifndef TAD_LISTA_CUENTAS_H
#define TAD_LISTA_CUENTAS_H
#include "TAD_CUENTA.h"
#define MAXVEC 20

typedef TRcuenta Tvec [MAXVEC];

typedef struct{
	Tvec lis;
	int tam;
}TRlista;

/****** EJERCICIO 8 ******/

TRlista cargarLista ();
void eliminarCuentaDeLista (TRlista *);
void mostrarPorDNI (TRlista);
void movimientoCuenta (TRlista *);
void agregarCuenta (TRlista *);
void mostrarCuentasVacias (TRlista);

void inicializarLista(TRlista *);
int listaVacia (TRlista);

#endif
