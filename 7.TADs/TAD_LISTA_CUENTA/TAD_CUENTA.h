#ifndef TAD_CUENTA_H
#define TAD_CUENTA_H
typedef long Tdni;
typedef struct{
	Tdni dni;
	int nro;
	int saldo;	
}TCuenta;

TCuenta cargarCuenta();
void mostrarCuenta(TCuenta);
int compararCuenta(TCuenta,TCuenta);
//int retornaSaldo(TCuenta);
Tdni retornaDni(TCuenta);
//void modificarSaldo(TCuenta *,int);

#endif
