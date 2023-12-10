/* Problema 3: Dada una lista de N números naturales, que representan 
las edades de los alumnos de una cátedra, ingresar una lista que se 
ordene a medida que se ingresan los datos.
Luego mostrar la lista ingresada y la lista formada.*/

#include <stdio.h>
/* Definición tipo de dato arreglo */
typedef int Tlista[30]; 

/*** ´PROTOTIPOS ***/

/* carga los elementos ordenados a medida que se ingresan*/
void cargaOrdenado(Tlista , int *);
/* Mostrar los N elementos de la lista */
void mostrarLis(Tlista,int );

int main(int argc, char *argv[]) {
	Tlista edades;  /* edades: variable de Tipo de Dato Arreglo */
	int N;
	
	cargaOrdenado(edades,&N);	
	printf("\nLista Ingresada\n");
	mostrarLis(edades,N);		
	return 0;
}

/*** DEFINICION DE MODULOS ***/ 

void cargaOrdenado(Tlista v, int *n1){
	int i,j,aux;
	printf("\nIngrese la cantidad de elementos de la lista= ");
	scanf("%d",n1);
	for(i=1;i<=*n1;i++){
		printf("\nIngrese un elemento: ");
		scanf("%d",&aux); 
		j=i-1;
		while (j!=0&& v[j]>aux){
			v[j+1]=v[j];
		    j=j-1;
		}
		v[j+1]=aux;	
}
}
	
void mostrarLis(Tlista v,int n1){
		int i;
		
		for(i=1;i<=n1;i++)
			printf("\nv[%d]= %d",i,v[i]);
}

