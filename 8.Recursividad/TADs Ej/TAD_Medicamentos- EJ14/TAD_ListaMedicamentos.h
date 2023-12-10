#ifndef TAD_LISTAMEDICAMENTOS_H
#define TAD_LISTAMEDICAMENTOS_H
#include "TAD_Medicamento.h"

typedef RMedicamento TVector[10];
typedef struct{
	TVector lis;
	int tam;
} TLista;

TLista iniciliza_lista();
TLista carga_medicamentos();
void agrega_medicamentos(TLista *);
void elimina_medicamentos(TLista *);
void modifica_medicamentos(TLista *);
void mostrar_medicamentos(TLista );
void mostrar_lab_vto(TLista );
void genera_stock(TLista , TLista *);
void ordenar_lab(TLista *);
int retorna_tam(TLista );

#endif
