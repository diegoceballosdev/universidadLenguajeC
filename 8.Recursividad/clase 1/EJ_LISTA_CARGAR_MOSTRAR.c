/*  Crear un programa recursivo  que cargue una lista de N números enteros y luego 
 muestre la lista.*/

#include <stdio.h>
#define TAMV 50
typedef int tvector[TAMV];

void cargarLista(tvector ,int *);//Cargar lista de N nros enteros;
void cargar_listaRec(tvector,int );// mod rec p/cargar elementos de una lis
void mostrarLista(tvector,int);//Mostrar lista de N nros enteros;
void mostrar_listaRec(tvector,int);// mod rec p/mostrar elementos de una lis


int main(int argc, char *argv[]) {
	int tam;
	tvector vec;
	
	cargarLista(vec ,&tam);
	mostrarLista(vec ,tam);
	
	return 0;
}

/*** IMPLEMENTACION **/

/******** CARGAR LISTA **************/
void cargar_listaRec(tvector B,int tam)
{
	if(tam>0)
	{
		cargar_listaRec(B,tam-1);
		printf("\n Ingrese elemento  %d: ",tam);
		scanf("%d",&B[tam]);
	}
}
void cargarLista(tvector vector,int *t){
	printf("\n Ingrese cdad elementos: ");
	scanf("%d",t);	
	cargar_listaRec(vector,*t);
}

/******** MOSTRAR LISTA **************/
void mostrar_listaRec(tvector vector,int tam)
{	
	if(tam>0)
	{
		mostrar_listaRec(vector,tam-1);
		printf("\n\n vector[%d]: %d",tam,vector[tam]);
	}	
}
void mostrarLista(tvector vector,int tam)
{	
	if(tam==0) printf("\n\nEl vector NO tiene elementos");
	else{
		mostrar_listaRec(vector,tam-1);
		printf("\n\n vector[%d]: %d",tam,vector[tam]);
	}	
}
