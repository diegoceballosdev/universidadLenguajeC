#ifndef TAD_LISTAEMPLEADOS_H
#define TAD_LISTAEMPLEADOS_H
#include "TAD_Empleados.h"

typedef REmpleado TVector[10];
typedef struct{
	TVector lis;
	int tam;
} TLista;


TLista inicializa_lista();
TLista carga_empleados();
void agrega_empleados(TLista *);
void elimina_empleados(TLista *);
void modifica_empleados(TLista *);
void mostrar_empleados(TLista );

void ordenar_esp(TLista *);
void mostrar_esp_turno(TLista );
void genera_esp_libre(TLista , TLista *);
int retorna_tam(TLista);
void ordenar_dni(TLista *);
#endif
