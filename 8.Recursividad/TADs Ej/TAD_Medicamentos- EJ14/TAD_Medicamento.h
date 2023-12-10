#ifndef TAD_MEDICAMENTO_H
#define TAD_MEDICAMENTO_H
#include "TAD_Cadena.h"

typedef struct{
	int cod, stock;
	TCadena des, lab;
	long felb, fvto;
}RMedicamento;


RMedicamento cargar_medicamento();
void mostrar_medicamento(RMedicamento);
void modificar_medicamento(RMedicamento *);
int retorna_COD(RMedicamento);
int compara_COD(RMedicamento, int);
int compara_LABVTO(RMedicamento, TCadena, long);
int compara_STOCK(RMedicamento, int);
int compara_LABS(RMedicamento, RMedicamento);



#endif
