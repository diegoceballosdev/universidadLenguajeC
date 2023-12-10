#ifndef TADLISTA_ENLAZADA_H
#define TADLISTA_ENLAZADA_H
#include "TADregistro.h"

typedef struct nodo{
	Reg_per dato;
	struct nodo *sig;
}T_nodo;

typedef T_nodo *T_ptr;

void agregar_uno_ordenado(T_ptr*);
void eliminar_unalumno(T_ptr*);
void mostrar_unalumno(T_ptr);
void cantidad_lyr(T_ptr);
void mostrar_lis_en(T_ptr);

#endif
