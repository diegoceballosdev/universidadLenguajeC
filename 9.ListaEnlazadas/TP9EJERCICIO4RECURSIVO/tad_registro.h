#ifndef TAD_REGISTRO_H
#define TAD_REGISTRO_H
#include "tad_cadena.h" 
/**ESTRUCTURA**/ 
typedef struct {
	long code ;
	tcad nombre ; 
	float precio ; 
	int stock ;
}treg ; 
/**OPERACIONES**/ 
treg carga_articulo (long ) ;
void mostrar_articulo (treg) ;
void modifica_articulo (treg* , long codigo ) ;
int compara_cad (treg , tcad ) ; 
int retorna_stock (treg) ; 
long retorna_code (treg) ; 
#endif
