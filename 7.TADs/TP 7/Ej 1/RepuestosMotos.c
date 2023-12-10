#include "RepuestosMotos.h"
#include <stdio.h>

/*********  PUBLICO  *********/

TRrepuestos cargarRepuesto (void){
	TRrepuestos aux;
	printf("\n INGRESE DATOS DEL PRODUCTO:");
	printf("\n Nombre:");
	fflush(stdin);
	leeCad(aux.nombre, MAXCAD);
	printf("\n Codigo:");
	scanf("%ld", &aux.codigo);
	printf("\n Precio por unidad:");
	scanf("%f", &aux.precio);
	printf("\n Stock disponible:");
	scanf("%d", &aux.stock);
	return aux;
}
void mostrarRepuesto (TRrepuestos A){
	printf("\n Repuesto: %s", A.nombre);
	printf("\n Codigo: %ld", A.codigo);
	printf("\n Precio: %f", A.precio);
	printf("\n Stock: %d", A.stock);
}
void modificarPrecio (TRrepuestos *A){
	printf("\n Precio actual: %f", A->precio);
	printf("\n Ingrese el nuevo precio:");
	scanf("%f", &A->precio);
	fflush(stdin);
	printf("\n El nuevo precio es: %f \n", A->precio);
}
int comparaStock (TRrepuestos A, TRrepuestos B){
	if (A.stock > B.stock)
		return 1;
	else if (A.stock < B.stock) 
		return -1;
	else 
		return 0;
}
long returnCod (TRrepuestos A){
	return A.codigo;
}
int returnstock (TRrepuestos A){
	return A.stock;
}
