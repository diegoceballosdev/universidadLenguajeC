#ifndef TADREGISTRO_H
#define TADREGISTRO_H
#include "TADcadena.h"
typedef struct{
	T_cad nomyape;
	long dni;
	short cond;
}Reg_per;

Reg_per cargar_reg();
void mostrar_reg(Reg_per);
long retorna_dni(Reg_per);
short retorna_cond(Reg_per);
#endif


