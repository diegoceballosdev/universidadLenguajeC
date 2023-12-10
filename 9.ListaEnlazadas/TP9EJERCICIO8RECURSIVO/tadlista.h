#ifndef TADLISTA_H
#define TADLISTA_H
#include "tadregistro.h"
/**ESTRUCTURA **/ 
typedef struct nodo{
	treg dato ; 
	struct nodo* sig ; 
}tnodo ; 
typedef tnodo* tlista ; 
/**OPERACIONES**/ 
tlista carga_lista ()  ;  
void inicializa (tlista*) ;
void mostrar_lista (tlista) ; 
void datos_repuesto (tlista) ; 
void modificar_precio (tlista) ; 
void repuesto_no_disponibles (tlista) ; 
void agrega (tlista *) ; 
int valor (tlista) ; 
#endif
