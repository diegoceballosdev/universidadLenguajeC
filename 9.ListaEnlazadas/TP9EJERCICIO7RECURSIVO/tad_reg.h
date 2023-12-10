#ifndef TAD_REG_H
#define TAD_REG_H
#include "tad_cad.h"
/**ESTRUCTURA**/ 
typedef struct {
	tcad ApeNom;
	long dni;
	int cond;
}Talumno ; 
/**OPERACIONES**/ 
Talumno carga_alumno(long);
void muestra_alumno(Talumno);
long retorna_dni(Talumno);
#endif
