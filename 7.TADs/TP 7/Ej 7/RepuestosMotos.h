#ifndef REPUESTOSMOTOS_H
#define REPUESTOSMOTOS_H

#include "TADCADENA.h"

typedef struct {
	Tcad nombre;
	long codigo;
	float precio;
	int stock;
}TRrepuestos;

//Del ejercicio
TRrepuestos cargarRepuesto (void);
void mostrarRepuesto (TRrepuestos);
int retornarStock (TRrepuestos);
void modificarPrecio (TRrepuestos *);

//Extras necesarios
long returnCod (TRrepuestos );
int returnStock (TRrepuestos );
int comparaCod (TRrepuestos, TRrepuestos);
void modificarNombre (TRrepuestos *);

int comparaNom(TRrepuestos, TRrepuestos);

#endif
	
