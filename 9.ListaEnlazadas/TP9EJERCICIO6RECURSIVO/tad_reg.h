#ifndef TAD_REG_H
#define TAD_REG_H
#include "tad_cad.h"
/**ESTRUCTURA**/ 
typedef struct{
	int nro , tipo ; 
	long dni ;
	tcad ApeNom ; 
}treg ; 
/**OPERACIONES**/ 
treg carga_reg (int) ;
void mostrar_reg (treg) ; 
void modif_reg (treg*) ; 
int retorna_nro (treg);
#endif
