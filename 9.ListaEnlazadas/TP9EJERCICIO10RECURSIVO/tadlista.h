#ifndef TADLISTA_H
#define TADLISTA_H
#include "tadreg.h" 
/**ESTRUCTURA**/ 
typedef struct nodo{
	treg dato ; 
	struct nodo* sig ; 
}tnodo;
typedef tnodo* tlista ;
/**OPERACIONES**/ 
void agrega_pedido (tlista*,tlista) ; 
void resueltos (tlista*,tlista*) ; 
void mostrar_lista (tlista); 
void control_fecha (tlista) ; 
void inicializa (tlista*) ; 
int valor (tlista); 
#endif
