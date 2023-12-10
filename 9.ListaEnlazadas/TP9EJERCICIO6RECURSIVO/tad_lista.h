#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "tad_reg.h" 
/**ESTRUCTURA**/ 
typedef struct nodo {
	treg dato ;
	struct nodo* sig; 
}tnodo ; 
typedef tnodo* tlista ; 
/**OPERACIONES**/ 
void inicializa (tlista*); 
void agrega (tlista*) ; 
void mostrar_reserva (tlista) ; 
void mostrar_lista (tlista) ; 
void modif_lista (tlista*) ;
int valor (tlista) ; 
#endif
