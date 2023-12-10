#ifndef TAD_EMPLEADOS_H
#define TAD_EMPLEADOS_H
#include "TAD_Cadena.h"

typedef struct{
	TCadena ape, nom;
	long dni;
	int esp, turno, tarea, est;
}REmpleado;


REmpleado cargar_empleado();
void mostrar_empleado(REmpleado);
void modificar_empleado(REmpleado *);

long retorna_DNI(REmpleado);
int compara_DNI(REmpleado, long);
int compara_emp_ET(REmpleado, int, int);
int compara_emp_esp(REmpleado, REmpleado);
int compara_RDNI(REmpleado, REmpleado);
#endif
