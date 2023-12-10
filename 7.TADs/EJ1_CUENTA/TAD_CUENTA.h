#ifndef TAD_CUENTA_H
#define TAD_CUENTA_H

typedef struct{
	long dni;
	int nro;
	int saldo;	
}TCuenta;

TCuenta cargarCuenta();
void mostrarCuenta(TCuenta);
int retornaSaldo(TCuenta);
long retornaDni(TCuenta);
void modificarSaldo(TCuenta *,int);

#endif
