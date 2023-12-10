/*Se pide crear un programa recursivo que permita generar aleatoriamente una lista 
de N números enteros en el intervalo [A,B], posteriormente, ingresar un número 
e indicar si se encuentra en la lista recientemente generada y finalmente mostrar la lista.*/

/*	Realizar una variante del ejercicio, indicando para el número ingresado, 
la cantidad de veces que aparece en la lista.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXVEC 10

typedef int Tvec [MAXVEC];

void cargarLista (Tvec, int *, int, int);
void cargarListaRec (Tvec, int, int , int );
int buscarNumRecSec (Tvec, int, int);
void mostrarLista (Tvec, int);
void mostrarListaRec (Tvec, int);

int main(void) {
	
	int N, num, A, B, pos;
	Tvec lista;
	srand(time(NULL));
	
	printf("\n Ingrese A y B para marcar el intervalo [A, B]: \n");
	scanf("%d %d", &A, &B);
	
	cargarLista (lista, &N, A, B);
	
	printf("\n Ingrese el numero a buscar: ");
	scanf("%d", &num);
	
	pos = buscarNumRecSec (lista, N, num);
	if (pos)
		printf("\n El numero %d SI esta en la lista", num);
	else
		printf("\n El numero %d NO esta en la lista", num);
	
	mostrarLista (lista, N);
	
	return 0;
}

/******** CARGAR LISTA **************/

void cargarLista(Tvec V, int *tam, int A, int B){
	printf("\n Ingrese la cantidad de numeros de la lista: ");
	scanf("%d", tam);
	cargarListaRec (V, *tam, A, B);
}
void cargarListaRec (Tvec V, int tam, int A, int B){
	if (tam > 0){
		cargarListaRec (V, tam-1, A, B);
		V[tam] = rand() % (B - A + 1) + A;
	} 
}

/******** MOSTRAR LISTA **************/
	
void mostrarListaRec (Tvec V, int tam){
	if(tam>0){
		mostrarListaRec(V, tam-1);
		printf("\n ELEMENTO[%d]: %d", tam, V[tam]);
	}
}

void mostrarLista (Tvec V, int tam){
	if(tam == 0) 
		printf("\nEl vector NO tiene elementos");
	else{
		mostrarListaRec(V, tam-1);
		printf("\n ELEMENTO[%d]: %d", tam, V[tam]);
	}
}

/******** BUSQUEDA SECUENCIAL **************/
	
int buscarNumRecSec (Tvec V, int tam, int bus){
	if (tam > 0)
		if(V[tam]==bus)
			return tam;
		else
			return buscarNumRecSec (V, tam-1, bus);
	else
			return 0;
}

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	









