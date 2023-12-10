#include "ListaRepuestos.h"
#include <stdio.h>

/******   Cargar Lista   ******/

void cargarVector (Tvec V, int tam){
	int i;
	for(i=1; i<=tam; i++){
		printf("\n %d° elemento de la lista:", i);
		V[i]=cargarRepuesto();
	}
}
Tlista cargarLista(){
	Tlista L;
	printf("\n Ingrese cantidad de elementos de la lista:");
	scanf("%d", &L.tam);
	cargarVector(L.vector, L.tam);	
	return L;
}
/******   Mostrar Lista   ******/

void mostrarVector(Tvec V ,int tam){
	int i;
	for(i=1; i<=tam; i++){
		printf("\n %d° elemento de la lista:", i);
		mostrarRepuesto(V[i]);
	}
}
void mostrarLista (Tlista L){
	mostrarVector(L.vector, L.tam);
}
	
/******   Ordenar Lista Por Codigo ******/
	
void ordenarLista(Tlista *L){
	int i, j;
	Tlista B; 
	TRrepuestos AUX;
	B = *L;
	for(i=1; i<=B.tam-1; i++){
		for(j=i+1; j<=B.tam; j++){
			if(comparaCod(B.vector[j], B.vector[i]) == -1){
				AUX = B.vector[i];
				B.vector[i] = B.vector[j];
				B.vector[j] = AUX;
			}
		}
	}
	*L = B;
}
	
/******   Mostrar elemento por su Codigo   ******/
	
int buscarCod (Tvec V, int tam, long cod){
	int i;
	while (i <= tam && returnCod(V[i]) != cod){
		i++;
	}
	if (i <= tam) 
		return 1;
	else
		return 0;
}

void mostrarRepuestoPorCod (Tlista L, long cod){
	int pos;
	pos = buscarCod (L.vector, L.tam, cod);
	if (pos == 1)
		mostrarRepuesto(L.vector[pos]);
	else
		printf("El codigo no coincide con ningun repuesto de la lista");
}

/******   Modificar Precio por su Codigo   ******/	
	
void modificarPrecioPorCod (Tlista L, long cod){
	int pos;
	pos = buscarCod (L.vector, L.tam, cod);
	if (pos == 1)
		modificarPrecio(&L.vector[pos]);
	else
		printf("El codigo no coincide con ningun repuesto de la lista");
}

/******   Mostrar repuestos sin Stock   ******/	
	
void mostrarRepSinStock (Tlista L){
	int i;
	for (i=1 ; i<=L.tam; i++){
		if (returnStock(L.vector[i]) == 0)
			mostrarRepuesto(L.vector[i]);
	}
}

