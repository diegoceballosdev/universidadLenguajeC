#include "TAD_LISTA.h"
#include <stdio.h>
#include <stdlib.h>

/*** VALIDAR DNI  ***/

int valida(Tlista cab, long doc){
	if (cab!=NULL)	{	
		while (cab->sig!=NULL && retorna_dni(cab->dato)!=doc)	
			cab=cab->sig;
		if (retorna_dni(cab->dato)==doc) 
			return 1;
		else 
			return 0;
	}
	else
		return 0;
}
	
/*** AGREGAR ALUMNO  ***/

Tlista crea_nodo(long doc){
	Tlista nvo;
	nvo=(Tlista)malloc(sizeof(Tnodo));
	nvo->dato =carga_alumno(doc);
	nvo->sig=NULL;
	return nvo;
}
	
void agrega_cab(Tlista *cab, Tlista nodo){
	nodo->sig= *cab;
	*cab=nodo;
}
	
void agrega_nodo(Tlista *cab, Tlista nodo){
	Tlista ant=NULL,aux=NULL;
	if (*cab==NULL) // la lista esta vacia
		*cab=nodo;
	else //lis NO vacia.Debo ubicar punteros ANT y DESP donde voy a agreg el nodo
	{
		aux=*cab;
		ant=NULL;						
		while (aux!=NULL && retorna_dni(nodo->dato)>retorna_dni(aux->dato)) 
		{	//se podría agregar un módulo que compare el campo dni de 2 nodos??
			ant=aux;
			aux = aux->sig;
		}
		if (ant==NULL) //debo agregar al principio de la lista 
			agrega_cab(cab,nodo);
		else{	//NO debo agregar al ppio de la lista
			ant->sig=nodo;
			nodo->sig=aux;
		}
	}
}
	
void agrega_alumno(Tlista *cab){
	Tlista nvo;
	int rta;
	long doc;
	do{
		printf("\nIngrese Numero de Documento: ");
		scanf("%ld", &doc);
		rta= valida(*cab, doc);
	} 
	while (rta!=0);
	nvo=crea_nodo(doc);
	agrega_nodo(cab,nvo);
}
	
/*** MOSTRAR LISTA***/
	
void muestra_lista(Tlista cab){
	if (cab!=NULL)	
		while (cab != NULL)	{
			muestra_alumno(cab->dato);
			cab=cab->sig;
	}
	else
		printf("\n lista vacia");
}
	
/*** MOSTRAR ALUMNO SEGUN DNI***/	

void MuestraAlumno(Tlista cab, long doc){
	if (cab!=NULL)	{	
		while (cab != NULL && retorna_dni(cab->dato)!=doc){
			//podría agreg un mód que compare el campo dni de un nodo con un long
			cab=cab->sig;
		}
		if (cab!=NULL) 
			muestra_alumno(cab->dato);
		else 
			printf("\nEl DNI no existe");
	}
	else	 
		printf("\nLista vacia");
}
	
void Mostrar_Alumno(Tlista cab){
	long doc;
	
	printf("\nIngrese DNI: ");
	scanf("%ld", &doc);
	MuestraAlumno(cab, doc);
}
	
/*** ELIMINAR SEGUN DNI ***/
	
void EliminaAlumno(Tlista *cab, long doc){
	Tlista aux,ant;
	
	if (*cab!=NULL){
		ant= NULL; 
		aux= *cab;
	
		while(aux!=NULL && retorna_dni(aux->dato)!=doc){ 
		ant= aux;
		aux= aux->sig; 
		}
		if(ant==NULL) { 
			*cab= aux->sig;
			aux->sig = NULL; 
		}
		else{ 
			if(aux!=NULL){
			ant->sig= aux->sig;
			aux->sig = NULL; 
			}
			else printf("\n No esta el valor"); }
		free(aux); 
	}
	else printf("\n Lista Vacia");
}
	
void Eliminar_Alumno(Tlista *cab){
	long doc;
	
	printf("\nIngrese DNI: ");
	scanf("%ld", &doc);
	EliminaAlumno(cab, doc);
}
	
/*** MENU ***/
	
int menu(){
	int op;
	printf("\n*************************************\n");
	printf("\nMenu de opciones");
	printf("\n ");
	printf("\n0: Salir del Programa");
	printf("\n1: Agregar un alumno nuevo");
	printf("\n2: Mostrar los datos de un alumno");
	printf("\n3: Eliminar un alumno");
	printf("\n4: Mostrar lista de alumnos");
	printf("\n ");
	printf("\nIngrese opcion deseada: ");
	scanf("%d", &op);
	return op;	
}
	
