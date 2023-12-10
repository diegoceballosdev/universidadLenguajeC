#include "RepuestosMotos.h"
#include <stdio.h>

/******   Cargar Registro   ******/	

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
	
/******   Mostrar Registro   ******/	
	
void mostrarRepuesto (TRrepuestos A){
	printf("\n Repuesto: %s", A.nombre);
	printf("\n Codigo: %ld", A.codigo);
	printf("\n Precio: %f", A.precio);
	printf("\n Stock: %d", A.stock);
}
	
/******   Modificar Precio   ******/	
	
void modificarPrecio (TRrepuestos *A){
	printf("\n Precio actual: %f", A->precio);
	printf("\n Ingrese el nuevo precio:");
	scanf("%f", &A->precio);
	fflush(stdin);
	printf("\n El nuevo precio es: %f \n", A->precio);
}
	
/******   Comparar campo de Dos Registros   ******/	
	
int comparaCod (TRrepuestos A, TRrepuestos B){
	if (A.codigo > B.codigo)
		return 1;
	else if (A.codigo < B.codigo) 
		return -1;
	else 
		return 0;
}
	
/******   Retornar valor de Codigo   ******/	
	
long returnCod (TRrepuestos A){
	return A.codigo;
}
	
/******   Retornar valor de stock   ******/	
	
int returnStock (TRrepuestos A){
	return A.stock;
}
