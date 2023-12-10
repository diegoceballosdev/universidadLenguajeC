/*  Se tiene una lista de artículos en stock de los cuales se registran los
siguientes datos: Código, Descripción y Precio.
Crear un programa recursivo  que cargue una lista de N artículos,luego la ordene
y mediante menu permita mostrar la lista y eliminar un elemento de la lista.*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_VEC 10
#define MAX_CAD 30
typedef char TCadena [MAX_CAD];

typedef struct{
	int cod;
	TCadena des;
	float precio;
}RArticulo;
typedef RArticulo TVector1 [MAX_VEC];


/** PROTOTIPOS  REGISTRO */
RArticulo carga_articulo();
void mostra_articulo(RArticulo);

/*(cadena)*/
void leeCad(TCadena, int);

/** PROTOTIPOS  LISTA DE REGISTROS */
void cargarLista(TVector1,int*);
void cargar_recursivo1(TVector1, int);
void mostrarLista(TVector1,int);
void mostrar_recursivo1(TVector1, int);
void ordenarLista(TVector1,int);
void mergesort1(TVector1, int, int);
void elimina_elemento(TVector1 ,int *);
void elimina_recursivo(TVector1, int,int );
int busbin_rec(TVector1, int, int, int);
float total_stock(TVector1, int);

void menu_recursivo(TVector1,int *);

int main() {
	int N,ini, fin;
	TVector1 A;
		
	
	cargarLista(A, &N);
	printf("\n ");
	printf("\nOrdenando la lista utilizando MSort");
	ini=1; fin=N;
	mergesort1(A, ini, fin);
	menu_recursivo(A,&N);
	return 0;
}
int opciones(){
	int r;
	printf("\n=======Menu de opciones========");
	printf("\nIngrese 1:  mostrar la lista ordenada");
	printf("\nIngrese 2: eliminar un nro de la lista");	
	printf("\nIngrese 3: Stock de articulos con codigos pares en $");	
	printf("\nIngrese 0: para salir del MENU");
	printf("\nIngrese su eleccion: ");
	scanf("%d", &r);
	return r;
}
	
void menu_recursivo(TVector1 l,int *n){
	int rta;
		
	rta=opciones();
	switch(rta){
		case 0: 
			printf("\n\nA elegido Salir del Programa"); 
			break;
		case 1: 
			if(*n>0) 
				mostrar_recursivo1(l,*n);
			else 
				printf("\nNo se puede mostrar lista, lista vacia");
			menu_recursivo(l, n); 
			break;
		case 2: 
			if(*n>0)
				elimina_elemento(l ,n);	
			else 
				printf("\n\nNo se pudo eliminar elemento, lista vacia");
			menu_recursivo(l, n); 	
			break;	
		case 3: if(*n>0)
			printf("\n\n Total stock de articulo con codigo pares en $ es: %f",total_stock(l,*n));
			menu_recursivo(l, n);
		default: 
			printf("\n\nA ingresado un valor no valido");
		menu_recursivo(l, n); 
		break;
	}
}	
void leeCad(TCadena cad, int tam){
	int j; 	
	char c;
	j=0;
	c=getchar();
	while (c!=EOF && c!='\n' && j<tam-1)
	{ 	cad[j]=c;
	j++;
	c=getchar(); 	}
	cad[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
}
RArticulo carga_articulo(){
	RArticulo aux;
	printf("\nIngrese el codigo: ");
	scanf("%d", &aux.cod);
	printf("\nIngrese la descripcion: ");
	fflush(stdin);
	leeCad(aux.des, 20);
	printf("\nIngrese el precio: ");
	scanf("%f", &aux.precio);
	return aux;
}
void mostrar_articulo(RArticulo aux){
	printf("\nEl codigo: %d", aux.cod);
	printf("\nLa descripcion: %s", aux.des);
	printf("\nEl precio: %f", aux.precio);
}

/******** CARGAR LISTA **************/	
void cargar_recursivo1(TVector1 A, int N){
	if (N>0){
		cargar_recursivo1(A, N-1);
		printf("\nIngrese A[%d]= ", N);
		A[N]= carga_articulo();
	}
}
	
void cargarLista(TVector1 l,int *N){
	printf("\nIngrese la cantidad de elementos de la lista: ");
	scanf("%d",N);
	cargar_recursivo1(l, *N);
}
/******** MOSTRAR LISTA **************/
void mostrar_recursivo1(TVector1 A, int N){
	if (N>0){	
		mostrar_recursivo1(A, N-1);
		mostrar_articulo(A[N]);
	}
}
void mostrarLista(TVector1 l,int tam){
	printf("\nlista de Articulos en Stock");
	mostrar_recursivo1(l,tam);
}

/******** ELIMINAR UN ELEMENTO DE LA LISTA **************/
int busbin_rec(TVector1 A, int ini, int fin, int bus){
	int med;
	med=(ini+fin)/2;
	if (ini<=fin) {
		if (A[med].cod==bus) 
			return med;
		else if(bus<A[med].cod) 
			return busbin_rec(A, ini, (med-1), bus);
		else 
			return busbin_rec(A, (med+1),fin , bus);}
	else 
		return -1; 
}
	
void elimina_recursivo(TVector1 A, int TAM,int POS){
	if(POS<TAM){
		A[POS]=A[POS+1];
		elimina_recursivo(A,TAM,POS+1);			
	}
}
		
void elimina_elemento(TVector1 A,int *T){
	int X,P;

	if(*T==0) 
		printf("\n\nEl vector NO tiene elementos: ");
	else {
		printf("\n\nIngrese el odigo del articulo que desea eliminar: ");
		scanf("%d",&X);
		P=busbin_rec(A,1,*T,X);
		if (P!=-1){
			elimina_recursivo(A,*T,P);
			printf("\nArticulo eliminado");
			*T=*T-1;
		}
		else
			printf("\n\nNo encontró el elemento");	
	}
}

void merge(TVector1 A, int ini, int med, int fin) {
	TVector1 aux; 
	int i,j,k,t;
	k=0;
	i=ini;
	j=med+1;
	while (i<=med && j<=fin){ 
		k++;
		if (A[i].cod<A[j].cod) {
			aux[k]=A[i];
			i++; 
		}
		else { 	
			aux[k]=A[j];
			j++; 
		}
	}
	for(t=i; t<=med; t++) { 
		k++;
		aux[k]=A[t]; 
	}
	for(t=j; t<=fin; t++) {
		k++;
		aux[k]=A[t]; 
	}
	for(t=1; t<=k; t++){
		A[ini+t-1]=aux[t]; 
	}
}

void mergesort1(TVector1 A, int ini, int fin) {
	int med;
	if(ini<fin){
		med= (ini+fin)/2;
		mergesort1(A, ini, med);
		mergesort1(A, med+1, fin);
		merge(A, ini, med, fin); 
	}
}

void ordenarLista(TVector1 l,int tam){
	printf("\n\nOrdenando Lista......");
	mergesort1(l,1,tam);
}
	
/******** calcular STOCK EN $$ **************/
float total_stock(TVector1 A, int N){
	if (N>0){ 
		if (A[N].cod %2==0) 
			return (A[N].precio+total_stock(A, N-1));
		else 
			return (total_stock(A, N-1));
	}
	else return 0;
}

