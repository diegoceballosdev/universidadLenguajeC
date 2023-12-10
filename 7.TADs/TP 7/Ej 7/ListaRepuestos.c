#include "ListaRepuestos.h"
#include <stdio.h>
#include <string.h>

/******   Cargar Lista (sin ordenar)  ******/

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
	
void ordenarListaCod(Tlista *L){
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
	
/******   Mostrar elemento dado un Codigo   ******/
	
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

/******   Modificar Precio dado uh Codigo   ******/	
	
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

/******   Cargar Lista Ordenadamente  ******/
	
Tlista inicializarLista(){
	Tlista aux;
	aux.tam=0;
	return aux;
}

void cargaOrdenada(Tvec V, int *tam){

	int i,j;
	TRrepuestos AUX;
	printf("\nIngrese la cantidad de elementos de la lista: "); 
	scanf("%d",tam);
	printf("\nIngrese el elemento V[1]: ");
	V[1] = cargarRepuesto ();
	
	for(i=2; i<=*tam; i++){
		
		printf("\nIngrese el elemento V[%d]: ", i);
		AUX = cargarRepuesto ();
		j=i-1;
		
		while(j!=0 && comparaCod(AUX,V[j]) == -1){
			V[j+1]=V[j];
			j--;
		}
		V[j+1]=AUX;
	}
}
	
Tlista cargarListaOrdenada (Tlista L){
	Tlista AUX;
	cargaOrdenada(L.vector, &AUX.tam);
	return AUX;	
}
	
/******   Modificar Precio dado un Codigo   ******/	
	
void modificarNombrePorCod (Tlista L, long cod){
	int pos;
	pos = buscarCod (L.vector, L.tam, cod);
	if (pos == 1)
		modificarNombre(&L.vector[pos]);
	else
		printf("El codigo no coincide con ningun repuesto de la lista");
	}

/******   Mostrar lista ordenada alfabeticamente   ******/
	
void ordenarListaAlf(Tlista *L){
	int i, j;
	Tlista B; 
	TRrepuestos AUX;
	B = *L;
	for(i=1; i<=B.tam-1; i++){
		for(j=i+1; j<=B.tam; j++){
			if(comparaNom(B.vector[j], B.vector[i]) == -1){
				AUX = B.vector[i];
				B.vector[i] = B.vector[j];
				B.vector[j] = AUX;
			}
		}
	}
	*L = B;
}
	
void mostrarLisOrdAlf (Tlista L){
	ordenarListaAlf(&L);
	mostrarLista(L);
}
