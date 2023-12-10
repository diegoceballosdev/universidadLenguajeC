#include "TAD_LISTA.h"

#include<stdio.h>

/* Implementación de Operaciones sobre TD Lista */
void Cargar_Vector(TVector AP, int NP) { /*Módulo Privado*/
	int I;
	for(I=1; I<=NP; I++){
		AP[I]=cargarCuenta();
	}
}

TLista Cargar_Lista(){/*Módulo Público, con prototipo en archivo de cabecera*/
	TLista LP;
	printf("\nIngrese la cantidad de elementos: ");
	scanf("%d", &LP.Tam);
	Cargar_Vector(LP.Lis, LP.Tam);
	return LP;
}
	
void Mostrar_lista(TLista LP) { /*Módulo Público*/
	int I;
	for(I=1; I<=LP.Tam; I++)
		mostrarCuenta(LP.Lis[I]);
	}
	
void Seleccion_Directa(TVector AP, int NP) { /*Módulo Privado*/
	int I, J;
	TCuenta Aux;
	for(I=1; I<NP; I++)
		for(J=I+1; J<=NP; J++)
		 if(compararCuenta(AP[J],AP[I])==-1){
			Aux=AP[I];
			AP[I]=AP[J];
			AP[J]=Aux;
		}
}		 

void Ordenar_lista(TLista *LP) { /*Módulo Público*/
	Seleccion_Directa(LP->Lis, LP->Tam);
}


int Buscar_Cuenta(TVector AP,int NP,long d){/* Modulo Privado*/
	int i;
	
	while(i<=NP && (retornaDni(AP[i]) != d)) 
		i++;
	if (i<=NP)return i;
	else return -1;
}
	

void Mostrar_Cuenta(TLista LP){
	int p;
	long doc;
	printf("\nIngrese el DNI del titular de la cuenta a mostrar: ");
	scanf("%ld",&doc);
	p=Buscar_Cuenta(LP.Lis,LP.Tam,doc);
	if(p!=-1) mostrarCuenta(LP.Lis[p]);
	else printf("\nNo existe titular con el DNI ingresado ");
}
