#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "tad_registro.h"
/**ESTRUCTURA**/ 
typedef struct nodo{
	treg dato ; 
	struct nodo* sig ; 
}tnodo ; 
typedef tnodo* tlista ; 
/**OPERACIONES**/ 
tlista carga_lista ();
void mostrar_lista (tlista) ; 
void elimina_uno (tlista*)  ;
void agrega (tlista*) ; 
void cambia_articulo (tlista) ; 
void random_prom (tlista) ; 
void inicializa (tlista*);
int valor (tlista) ; 
#endif
