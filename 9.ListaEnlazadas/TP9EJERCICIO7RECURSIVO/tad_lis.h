#ifndef TAD_LIS_H
#define TAD_LIS_H
#include "tad_reg.h"
/**ESTRUCTURA**/ 
typedef struct nodo{
	Talumno dato;
	struct nodo *sig;
} Tnodo;
typedef Tnodo* Tlista;
/**OPERACIONES**/ 
void inicializa (Tlista*); 
void agrega_alumno(Tlista *);
void Muestra_Lista(Tlista ) ; 
void MuestraAlumno(Tlista );
void Eliminar_Alumno(Tlista *); 
#endif
