/* Problema 2: Dada una lista de N números naturales, que representan las edades 
de los alumnos de una cátedra, formar una nueva lista con las edades pares.
Luego mostrar la lista ingresada y la lista formada.*/

#include <stdio.h>

/* Definición tipo de dato arreglo */
typedef int Tlista[30]; 

/* ´PROTOTIPOS */

void cargarLis(Tlista,int *);/* Cargar los N elementos de la lista */
float promedioLis(Tlista,int);/* Calcular promedio de los N elementos de la lista */
void mostrarLis(Tlista,int );/* Mostrar los N elementos de la lista */

int main(int argc, char *argv[]) {
	Tlista edades,L;  /* edades: variable de Tipo de Dato Arreglo */
	int N,t,i;
	
	cargarLis(edades,&N);
	/* Recorrer lista edades para Determinar edades pares - Formar nueva lista */
	t=0;   /* t: indice de la lista a formar*/
	for(i=1;i<=N;i++)
		if (edades[i]%2==0){
			t++; 
			L[t]=edades[i];
		}
	printf("\nLista Ingresada\n");
	mostrarLis(edades,N);	
	if(t>0) /*  si la lista formada tiene elementos */
	{
		printf("\nLista Formada\n");
		mostrarLis(L,t);}
	else
		printf("\nNo se ingreso ninguna edad par");
	return 0;
}

/* DEFINICION DE MODULOS */ 

void cargarLis(Tlista v,int *n1){
	int i;
	
	printf("\nIngrese la cantidad de elementos de la lista= ");
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

