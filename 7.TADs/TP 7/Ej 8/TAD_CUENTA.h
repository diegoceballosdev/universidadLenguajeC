#ifndef TAD_CUENTA_H
#define TAD_CUENTA_H
#include "TAD_CADENA.h"

typedef struct {
	Tcad ApeNom;
	long DNI;
	int cuenta, saldo;
}TRcuenta;

/****** EJERCICIO 2 ******/

TRcuenta cargarCuenta (int);
void mostrarCuenta (TRcuenta);
int retornaSaldo (TRcuenta);
long retornaDNI (TRcuenta);
void modificarSaldo (TRcuenta *, int);

void agregarSaldo (TRcuenta *);
void retirarSaldo (TRcuenta *);

/****** EJERCICIO 3 ******/

int comparaNombre (TRcuenta, TRcuenta);
void mostrarOrdAlf (TRcuenta , TRcuenta , TRcuenta);

/****** EJERCICIO 8 ******/

int comparaCuenta (TRcuenta, TRcuenta);
int retornaNroCuenta (TRcuenta);

#endif
