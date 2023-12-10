/* EJEMPLO 1: Diseñar un programa que, mediante asignación dinámica de memoria, 
ingrese y muestre una lista de nros naturales, agregando cada natural al principio de la lista.
     a)Posteriormente, debe calcular y mostrar la cantidad de números pares que tiene la lista.
     b)Posteriormente, debe calcular la cantidad de números pares que tiene la lista.y 
agregar ese dato al final de la lista. Mostrar la lista final.
*/

#include <stdio.h>
#include <stdlib.h>

/** Declaracion de la Estructura de una lista TDPuntero**/
typedef struct nodo {
	int dato;
	struct nodo* sig;
} T_nodo;

typedef T_nodo* T_ptr; // TD Puntero al que se le asigna el nombre T_ptr;

/** Prototipos **/
/* Dato*/
int ing_dato(void);
void muestra_dato(int);

/* Lista enlazada*/
T_ptr crea_nodo(int);
T_ptr crea_lista(void);
void agrega_cab(T_ptr*, T_ptr);
void agrega_fin(T_ptr*, T_ptr);
void muestra_lista(T_ptr);
int cuenta_pares(T_ptr);
int cuenta_impares(T_ptr);

int main(void){
	T_ptr lista,nue;
	int pares;
	
	lista=crea_lista();
	muestra_lista(lista);
	/* Calcular y Mostrar cantidad de nros pares de la lista enlazada*/
	pares=cuenta_pares(lista);
	printf("\nCantidad de pares de la lista: %d",pares);
	/* calcular cantidad de nros pares de la lista y agregar ese dato al final de la lista. */
	nue=crea_nodo(pares);
	agrega_fin(&lista, nue);
	/* Mostrar la lista final */
	muestra_lista(lista);
	
	/* calcular la cantidad  de números impares, agregando también al final de la lista*/
	nue=crea_nodo(cuenta_impares(lista));
	agrega_fin(&lista, nue);
	/* Mostrar la lista enlazada */
	muestra_lista(lista);
	return 0;
}
	
/** implementacion **/

int ing_dato(void){
	int n;
	printf("\n Ingrese un nro natural: ");
	scanf("%d",&n);
	return n;
}

void muestra_dato(int dato){
	printf("\n Nro:%d", dato);
}
T_ptr crea_nodo(int nro){
	T_ptr nvo;
	nvo=(T_ptr)malloc(sizeof(T_nodo));
	nvo->dato=nro;
	nvo->sig=NULL;
	return nvo;
}	
void agrega_cab(T_ptr* lista1, T_ptr nodo){
	nodo->sig=*lista1;
	*lista1=nodo;
}
void agrega_fin(T_ptr* lista1, T_ptr nodo){
	T_ptr aux;
	if(*lista1 !=NULL){
	    aux=*lista1;
		while (aux->sig !=NULL)
			aux=aux->sig;
		aux->sig=nodo;
		nodo->sig=NULL;	
	}	
	else *lista1=nodo;
}
/*	
T_ptr crea_lista(void){// conozco la cantidad de elementos de la lista
	T_ptr lis, uno;
	int i,n, nro;
	lis=NULL;
	printf("\n Ingrese cantidad de nros a procesar: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		nro=ing_dato();
		uno=crea_nodo(nro);
		agrega_cab(&lis, uno);
	}
	return lis;
}
	*/
T_ptr crea_lista(void){ // NO conozco la cantidad de elementos de la lista
	T_ptr lis, nvo;
	int nro; //Que sucede si ingreso un nro real??? - ver como mejorar este modulo
		lis=NULL;
		printf("\n Ingrese datos de la lista. Ingrese un nro negativo para terminar");
		nro=ing_dato();
		while (nro>0 && nro==(int)nro) {			
			nvo=crea_nodo(nro);
			agrega_cab(&lis,nvo);			 
			nro=ing_dato();}
		return lis;
}	
		
int cuenta_pares(T_ptr lista1){
	int c;
	c=0;
	while (lista1!=NULL){
			if(lista1->dato %2==0) c++;
			lista1=lista1->sig;	}		
	return c;	
}

int cuenta_impares(T_ptr lista1){
	int c;
	c=0;
	while (lista1!=NULL){
		if(lista1->dato %2 !=0) c++;
		lista1=lista1->sig;
	}		
	return c;	
}

void muestra_lista(T_ptr lista1){
	if (lista1!=NULL){
		printf("\n inicio de lista: \n");
		while (lista1!=NULL){
			muestra_dato(lista1->dato);
			lista1=lista1->sig;
		}
		printf("\n fin de lista \n");
	}
	else
		printf("\n lista vacía \n");		
}
	
	
	
	
/*** Pendiente ****/
void agrega_ant_par(T_ptr *lista1){
	T_ptr post, ant,nodo;
	
	post=*lista1;
	if(post!=NULL){
		ant=NULL;		
	    while ((post !=NULL) && (post->dato %2!=0)){
			ant=post;
			post=post->sig;
		}
		if(post != NULL){
			nodo=crea_nodo(post->dato+1);
			nodo->sig=post;
			if(ant!=NULL)
				ant->sig=nodo;
			else
				*lista1=nodo;
		}
	}		
}
/*** Pendiente ****/
void agrega_ant_pares(T_ptr *lista1){
	T_ptr post, ant,nodo;
	
	post=*lista1;
	if(post!=NULL){
		ant=NULL;		
		while ((post !=NULL)){
			
			if (post->dato %2==0){				
				nodo=crea_nodo(post->dato+1);
			    nodo->sig=post;
			    if(ant!=NULL)
			    	ant->sig=nodo;
			    else
				   *lista1=nodo;			
			}
			ant=post;
			post=post->sig;
		}
		
	}		
	
}
