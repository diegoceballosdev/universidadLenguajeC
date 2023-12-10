#ifndef TAD_CUENTA_H
#define TAD_CUENTA_H

typedef struct {
	long DNI;
	int cuenta, saldo;
}TRcuenta;

TRcuenta cargarCuenta ();
void mostrarCuenta (TRcuenta);
int retornaSaldo (TRcuenta);
long retornaDNI (TRcuenta);
void modificarSaldo (TRcuenta *, int);

void agregarSaldo (TRcuenta *);
void retirarSaldo (TRcuenta *);

#endif
