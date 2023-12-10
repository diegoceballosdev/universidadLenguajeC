#ifndef LISTAREPUESTOS_H
#define LISTAREPUESTOS_H
#include "RepuestosMotos.h"

#define MAXVEC 30

typedef TRrepuestos Tvec [MAXVEC];

typedef struct{
	Tvec vector;
	int tam;
}Tlista;

Tlista cargarLista();
void ordenarLista(Tlista *);
void mostrarLista(Tlista);
void mostrarRepuestoPorCod (Tlista, long);
void modificarPrecioPorCod (Tlista L, long cod);
void mostrarRepSinStock(Tlista );

#endif
