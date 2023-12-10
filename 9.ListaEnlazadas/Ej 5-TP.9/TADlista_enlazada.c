#include<stdio.h>
#include "TADlista_enlazada.h"

T_ptr crear_nodo(){
	T_ptr aux=NULL;
	aux=(T_ptr)malloc(sizeof(T_nodo));
	aux->dato=cargar_reg();
	aux->sig=NULL;
	return aux;
}

	

void agregar_uno_ordenado(T_ptr *aux){
	T_ptr nue=NULL,ant=NULL,ult=NULL;
	if(*aux==NULL){
		*aux=crear_nodo();
	}
	else{
		ult=*aux;
		nue=crear_nodo();
		while(retorna_dni(nue->dato)>retorna_dni(ult->dato) && ult!=NULL){
			ant=ult;
			ult=ult->sig;
		}
		if (ult==NULL){
			ant->sig=nue;
		}
		else{
			if (ant==NULL){
				nue->sig=*aux;
				*aux=nue;
			}
			else{
				nue->sig=ult;
				ant->sig=nue;
			}
		}
	}
}	

void eliminar_nodo(T_ptr *cab, long bus){
	T_ptr com=NULL,ant=NULL;
	com=*cab;
	while(retorna_dni(com->dato)!=bus && com!=NULL){
		ant=com;
		com=com->sig;
	}
	if(com==NULL){
		printf("\nNo se encuentra el dni");
	}
	else {
		if(ant==NULL){
			*cab=com->sig;
		}
		else{
			ant->sig=com->sig;
		}
		com->sig=NULL;
		free(com);
	}
}
	
void eliminar_unalumno(T_ptr *cab){
	long bus;
	printf("\nIngrese DNI del alumno a eliminar: ");
	scanf("%ld",&bus);
	eliminar_nodo(cab,bus);
}

		
void mostrar_unalumno(T_ptr cab){
	long bdni;
	printf("\nIngrese DNI del alumno a mostrar: ");
	scanf("%ld",&bdni);
	while(retorna_dni(cab->dato)!=bdni && cab!=NULL){
		cab=cab->sig;
	}
	if(cab!=NULL){
		mostrar_reg(cab->dato);
	}
	else{
		printf("\nDNI no encontrado");
	}
}

void cantidad_lyr(T_ptr cab){
	int reg=0, lib=0;
	while(cab!=NULL){
		if(retorna_cond(cab->dato)==1){
			reg++;
		}
		else{
			lib++;
		}
		cab=cab->sig;
	}
	printf("\nCantidad de alumnos regulares: %d",reg);
	printf("\nCantidad de alumnos libres: %d",lib);
	printf("\n");
}
	
void mostrar_lis_en(T_ptr cab){
	int lis=0;
	if(cab==NULL){
		printf("\nLista vacia");
	}
	else {
		while(cab!=NULL){
			lis++;
			printf("\nAlumno N°%d",lis);
			mostrar_reg(cab->dato);
			cab=cab->sig;
		}
	}
}
