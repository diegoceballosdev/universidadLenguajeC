/* Problema 1: Dada una lista de N números naturales, que representan las edades 
de los alumnos de una cátedra, calcular  y mostrar la edad promedio. 
Luego mostrar la lista ingresada.*/

#include <stdio.h>

/* Definición tipo de dato arreglo */
typedef int Tlista[30]; 

/* ´PROTOTIPOS */
void cargarLis(Tlista,int *);/* Cargar los N elementos de la lista */
float promedioLis(Tlista,int);/* Calcular promedio de los N elementos de la lista */
void mostrarLis(Tlista,int );/* Mostrar los N elementos de la lista */

int main(int argc, char *argv[]) {
	Tlista edades;  /* edades: variable de Tipo de Dato Arreglo */
	int N;
	float prom;
	
	cargarLis(edades,&N);
	prom=promedioLis(edades,N);
	printf("\nLa edad promedio es: %f", prom);
	mostrarLis(edades,N);	
	return 0;
}
/* DEFINICION DE MODULOS */ 
void cargarLis(Tlista v,int *n1){
	int i;
	
	printf("\nIngrese la cantidad de elementos de la lista");
	scanf("%d",n1);
	for(i=1;i<=*n1;i++){
		printf("\nIngrese v[%d]= ",i);
		scanf("%d",&v[i]); /*elemento pasado por referencia*/
	}
}
float promedioLis(Tlista v,int n1){
	int i,sumaE;
	float p;
	
	sumaE=0;
	for(i=1;i<=n1;i++)
		sumaE +=v[i];  /* es igual a escribir sumaE=sumaE+v[i]*/
	p=(float)sumaE/n1;
	return p;		//se podría abreviar escibiendo: return ((float)sumaE/n1);
}
	
void mostrarLis(Tlista v,int n1){
		int i;
		
		for(i=1;i<=n1;i++)
			printf("\nv[%d]= %d",i,v[i]);
}

