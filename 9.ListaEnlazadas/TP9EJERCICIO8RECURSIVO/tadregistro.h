#ifndef TADREGISTRO_H
#define TADREGISTRO_H
#include "tadcadena.h"
/**ESTRUCTURA**/
typedef struct {
	tcad nombre ; 
	long codigo ; 
	float precio ;
	int cantidad ; 
}treg ;
/**OPERACIONES**/
treg carga_repuesto (long) ;
void mostrar_repuesto (treg) ; 
void modifica_precio (treg*) ; 
long retorna_codigo (treg);
int retorna_cant (treg) ; 
#endif
