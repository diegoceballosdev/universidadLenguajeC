#ifndef TADREG_H
#define TADREG_H
#include "tadcadena.h"
/**ESTRUCTURA**/ 
typedef struct {
	tcad descripcion ; 
	long fecha , pedido ;
	float abonado ; 
}treg ; 
/**OPERACIONES**/ 
treg carga_pedido (long); 
void mostrar_pedido  (treg) ; 
long  retorna_fecha (treg) ; 
long retorna_nro (treg ) ; 
#endif
