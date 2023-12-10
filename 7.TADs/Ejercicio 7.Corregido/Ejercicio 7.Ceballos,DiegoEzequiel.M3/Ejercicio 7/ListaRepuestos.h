#ifndef LISTAREPUESTOS_H
#define LISTAREPUESTOS_H
#include "RepuestosMotos.h"

#define MAXVEC 30

typedef TRrepuestos Tvec [MAXVEC];

typedef struct{
	Tvec vector;
	int tam;
}Tlista;

//Del ejercicio 6
Tlista cargarLista();
void ordenarListaCod(Tlista *);
void mostrarLista(Tlista);
void mostrarRepuestoPorCod (Tlista, long);
void modificarPrecioPorCod (Tlista L, long cod);
void mostrarRepSinStock(Tlista );

//Del ejercicio 7
Tlista inicializarLista();
Tlista cargarListaOrdenada();
void modificarNombrePorCod (Tlista , long );
void mostrarLisOrdAlf (Tlista);

#endif
