#ifndef TAD_LISTA_H
#define TAD_LISTA_H

#include "TAD_CUENTA.h"
#define MAX_VEC 100

typedef TCuenta TVector[MAX_VEC];

typedef struct{/*Se declara un TD Arreglo de registros como un registro que contiene dos campos*/
	TVector Lis;/*un campo Lis, que representa la lista de tipo de dato TVector*/
	int Tam; /*un campo Tam, que representa el tamaño de la lista*/
}TLista;/*Esta es la representación de un TD Lista, con una estructura registro*/

/* Declaración de Operaciones sobre TD Lista */
TLista Cargar_Lista();/*El prototipo cargar una lista, prestar atención que se
                       declara como una función en un TAD*/
void Mostrar_lista(TLista);
void Ordenar_lista(TLista *);
void Mostrar_Cuenta(TLista);/* Mostrar datos de una cuenta, dado el dni del titular*/

#endif
