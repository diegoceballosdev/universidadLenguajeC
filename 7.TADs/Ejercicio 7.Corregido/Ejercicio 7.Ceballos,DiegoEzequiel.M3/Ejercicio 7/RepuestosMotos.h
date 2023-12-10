#ifndef REPUESTOSMOTOS_H
#define REPUESTOSMOTOS_H

#include "TADCADENA.h"

typedef struct {
	Tcad nombre;
	long codigo;
	float precio;
	int stock;
}TRrepuestos;

//Del ejercicio 1 y 6
TRrepuestos cargarRepuesto (void);
void mostrarRepuesto (TRrepuestos);
int retornarStock (TRrepuestos);
void modificarPrecio (TRrepuestos *);
long returnCod (TRrepuestos );
int returnStock (TRrepuestos );
int comparaCod (TRrepuestos, TRrepuestos);

//Del ejercicio 7
void modificarNombre (TRrepuestos *);
int comparaNom(TRrepuestos, TRrepuestos);

#endif
	
