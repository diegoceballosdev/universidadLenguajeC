/* Problema 1: Dada una lista con las edades de N estudiantes y un número natural X, 
ingresado por teclado, se solicita informar si dicho número se encuentra en la 
lista ingresada y en qué posición ( Suponer que la lista A, no está ordenada)

*/
#include <stdio.h>
typedef int Tlista[30]; /* Definición tipo de dato arreglo */

/* ´PROTOTIPOS */
void cargarLis(Tlista,int *);/*Carga lista de edades*/
int buscaEdad(Tlista,int,int);/* Busca un nro en la lista */

int main(int argc, char *argv[]) {
	Tlista edades;  /* edades: variable de Tipo de Dato Arreglo */
	int N,X,pos;
	
	cargarLis(edades,&N);	
	printf("\nIngrese la edad a buscar: ");
	scanf("%d",&X);
	
	/*.....COMPLETAR ...*/
	
	return 0;
}
/****** DEFINICION DE MODULOS *****/
void cargarLis(Tlista v,int *n1){
	
	/* ...COMPLETAR ...*/
	
}
	
	
int buscaEdad(Tlista e,int n1,int eb){
	int i;
		
	i=1;	
	while(i<=n1&& eb!=e[i])
		i++;
	if(i<=n1)
		return i;
	else
		return -1;
		
	}
		
