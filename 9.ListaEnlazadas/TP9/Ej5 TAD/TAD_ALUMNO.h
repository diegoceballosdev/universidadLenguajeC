#ifndef TAD_ALUMNO_H
#define TAD_ALUMNO_H
#include "TAD_CADENA.h"

typedef struct{
	Tcad ApeNom;
	long dni;
	int cond;
}Talumno;

Talumno carga_alumno(long);
void muestra_alumno(Talumno);
long retorna_dni(Talumno);

#endif
