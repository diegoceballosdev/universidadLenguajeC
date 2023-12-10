#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int dato, may, cont;
	struct nodo *sig;
}Tnodo;

typedef Tnodo *Tlista;

Tlista crearNodo (int);
void agregaLista (Tlista *, int);
void agregaCabeza (Tlista *, Tlista);
void agregaFinal (Tlista *, Tlista);
void mostrarLista(Tlista);
void determinarMayor(Tlista, int *, int *);
void contadorMayor(Tlista, int, int *);
int menu();
int determinarPrimo(int );
void modificarPrimo(Tlista *);
void insertarCero(Tlista *);

int main(int argc, char *argv[]) {
	int num, op, cont, may;
	Tlista L;
	L = NULL;
	
	do{
		op = menu();
		switch(op){
		case 0:
			printf("\n FIN DEL PROGRAMA");
			break;
		case 1:
			printf("\n Ingrese un numero natural: ");
			scanf("%d", &num);
			agregaLista(&L, num);
			break;
		case 2:
			mostrarLista(L);
			break;
		case 3:
			may = 0;
			cont = 0;
			determinarMayor(L, &may, &cont);
			break;
		case 4:
			modificarPrimo(&L);
			break;
		case 5:
			insertarCero(&L);
			break;
		default:
			printf("\n INGRESE UNA OPCION VALIDA");
			break;
		}
	}while(op!=0);
	
	return 0;
}

int menu(){
	int op;
	printf("\n 0[SALIR]");
	printf("\n 1[AGREGAR UN NUMERO A LA LISTA]");
	printf("\n 2[MOSTRAR LISTA]");
	printf("\n 3[DETERMINAR MAYOR Y SUS APARICIONES]");
	printf("\n 4[CONVERTIR PRIMOS EN NEGATIVOS]");
	printf("\n 5[INSERTAR CEROS DELANTE DE NUMEROS PARES]");
	printf("\n Ingrese una opcion");
	scanf("%d", &op);
	return op;
}
	
/* Agregar un Num. a la lista */
	
Tlista crearNodo (int num){
	Tlista nodo;
	nodo = (Tlista) malloc(sizeof(Tnodo));
	nodo->dato = num;
	nodo->sig = NULL;
	return nodo;
}
	
void agregaCabeza (Tlista *lis, Tlista nvo){
	nvo->sig = *lis;
	*lis = nvo;
}
	
void agregaFinal(Tlista *lis, Tlista nvo){
	Tlista aux;
	if (*lis == NULL)
		*lis = nvo;
	else{
		aux = *lis;
		while(aux->sig != NULL){
			aux = aux->sig;
		}
		aux->sig = nvo;
	}
}

void agregaLista (Tlista *lis, int num){
	Tlista nvo;
	nvo = crearNodo(num);
	if (nvo->dato % 2 == 0)
		agregaCabeza (lis, nvo);
	else
		agregaFinal(lis, nvo);
}
	
/* Mostrar lista */

void mostrarLista (Tlista lis){
	Tlista aux;
	if (lis == NULL)
		printf("\n LISTA VACIA");
	else{
		aux = lis;
		while(aux != NULL){
			printf("\n Num = %d", aux->dato);
			aux = aux->sig;
		}
	}
}

/* Mayor */
	
void contadorMayor (Tlista lis, int may, int *cont){
	while(lis != NULL){
		if (lis->dato == may)
			*cont = *cont + 1;
		lis = lis->sig;
	}
}

void determinarMayor(Tlista lis, int *may, int *cont){
	Tlista aux;
	if (lis == NULL)
		printf("\n LISTA VACIA");
	else{
		aux = lis;
		while (aux != NULL){
			if (aux->dato > *may)
				*may = aux->dato;
			aux = aux->sig;
		}
		contadorMayor(lis, *may, cont);
		printf("\n El mayor de la lista es: %d", *may);
		printf("\n Apariciones: %d", *cont);
	}
}

/* Modificar Primo */	
	
int determinarPrimo(int num){
	int pd;
	pd = 2;
	while (pd<=(num/2) && (num%pd)!=0){
		pd++;
	}
	if (pd>(num/2) && num!=1)
		return 1;
	else
		return 0;
}

void modificarPrimo(Tlista *lis){
	Tlista aux;
	if (*lis==NULL)
		printf("\n LISTA VACIA");
	else{
		aux = *lis;
		while (aux != NULL){
			if (determinarPrimo(aux->dato))
				aux->dato = -(aux->dato);
			aux = aux->sig;
		}
	}
}

/* INSERTAR CERO DELANTE DE PAR */	
	
void insertarCero(Tlista *lis){
	Tlista aux, ant, nodo;
	int x;
	if (*lis == NULL)
		printf("\n LISTA VACIA");
	else{
		x=0;
		ant = NULL;
		aux = *lis;
		while (aux != NULL){
			if ((aux->dato) % 2 == 0){
				nodo = crearNodo(x);
				ant->sig = nodo;
				nodo->sig = aux;
			}
			ant = aux;
			aux = aux->sig;
		}
		mostrarLista(*lis);
	}
}
