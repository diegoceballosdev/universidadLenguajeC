/* Problema 2: Dada una lista con las edades de N estudiantes y un número 
natural X,ingresado por teclado, se solicita ordenar la lista y luego 
informar si dicho número se encuentra en la lista A ingresada */

#include <stdio.h>
typedef int Tlista[30]; /* Definición tipo de dato arreglo */

/*** ´PROTOTIPOS ****/
void cargarLis(Tlista,int *);/*Carga lista de edades*/
void ordenaLis(Tlista,int); /* Ordena lista */
int busqBinaria(Tlista,int,int);/* Busca un nro en la lista */

int main(int argc, char *argv[]) {
	Tlista edades;  /* edades: variable de Tipo de Dato Arreglo */
	int N,X,pos;
	
	cargarLis(edades,&N);	
	ordenaLis(edades,N);
	printf("\nIngrese la edad a buscar: ");
	scanf("%d",&X);
	pos=busqBinaria(edades,N,X);
	if(pos!=-1)
	    printf("\nLa edad ingresada se encuentra el la posición %d", pos);
	else
		printf("\nNo se encontró la edad ingresada");
			
	return 0;
}

/****** DEFINICION DE MODULOS *****/

void cargarLis(Tlista v,int *n1){
	int i;
	
	printf("\nIngrese la cantidad de elementos de la lista= ");
	scanf("%d",n1);
	for(i=1;i<=*n1;i++){
		printf("\nIngrese elemento[%d]= ",i);
		scanf("%d",&v[i]); /*elemento pasado por referencia*/
	}
}

void ordenaLis(Tlista v,int n1){
	int i,j,aux;
	for(i=1;i<n1;i++){
		for (j=i+1;j<=n1;j++){			
			if(v[j]<v[i]){
				aux=v[j];
				v[j]=v[i];
				v[i]=aux;
			}
				
		}
	}
}
	
int busqBinaria(Tlista v,int n1,int b){
	int ini,fin,med;
		
	ini=1;fin=n1;med=(ini+fin)/2;
		
	while(ini<=fin && v[med]!=b){
			if(v[med]<b)
				ini=med+1;
			else fin=med-1;
			med=(ini+fin)/2;
	}
	if(ini<=fin) return med;
	else return -1;	
}

	
