#ifndef TAD_LISTA_H
#define TAD_LISTA_H
#include "TAD_ALUMNO.h"

typedef struct nodo{
	Talumno dato;
	struct nodo *sig;
}Tnodo;

typedef Tnodo* Tlista;

//int valida(Tlista, long);

Tlista crea_nodo();
void agrega_cab(Tlista *, Tlista);
void agrega_nodo(Tlista *, Tlista);
void muestra_lista(Tlista);
void agrega_alumno(Tlista *);
void MuestraAlumno(Tlista, long);//ubica el dni del alu y lo muestra
void Mostrar_Alumno(Tlista);//ingrese dni del alumno a mostrar datos
void Eliminar_Alumno(Tlista*);//ingrese dni del alumno a elimina
void EliminaAlumno(Tlista *, long);//ubica el dni del alumno a eliminar

/*** Otros ***/
int menu(void);

#endif
