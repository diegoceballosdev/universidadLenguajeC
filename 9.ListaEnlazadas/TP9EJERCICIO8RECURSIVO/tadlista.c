#include "tadlista.h"
/**MODULOS PRIVADOS**/ 
int valida (tlista lis , long codigo ){
	if (lis!=NULL){
		if (retorna_codigo(lis->dato)==codigo) 
			return 1 ; 
		else 
			return valida (lis->sig , codigo) ; 
	}
	else 
		return -1 ; 
}
long codigo_valido (tlista lis){
	long codigo ;
	printf ("\nIngrese el codigo: ") ; 
	scanf ("%ld",&codigo) ; 
	if (valida(lis,codigo)!=1) 
		return codigo ; 
	else 
		return codigo_valido (lis) ; 
	}
tlista crea_nodo (long code ){
	tlista nvo ; 
	nvo=(tlista)malloc(sizeof(tnodo)); 
	nvo->dato=carga_repuesto(code) ; 
	nvo->sig= NULL; 
	return nvo ;
}
void agrega_ordenado (tlista *lis , tlista aux , tlista ant , tlista nodo ){
	if (aux!=NULL){
		if (retorna_codigo(aux->dato)<retorna_codigo(nodo->dato))
			agrega_ordenado(lis,aux->sig,aux,nodo) ; 
		else 
			if (ant==NULL) {
				nodo->sig=*lis ;
				*lis=nodo ; }
			else {
				ant->sig=nodo ;
				nodo->sig=aux ; }
    }
	else 
		if (*lis==NULL)
			*lis=nodo ; 
		else 
			ant->sig=nodo ; 
}
void carga_rec (tlista *lis, tlista nodo, int tam ){
	tlista aux , ant ; 
	aux=NULL , ant =NULL ; 
	long cod ; 
	if (tam>0){
		cod=codigo_valido(*lis) ; 
		nodo=crea_nodo(cod) ;
		aux=*lis ; 
		agrega_ordenado (lis,aux,ant,nodo); 
		carga_rec (lis,nodo,tam-1); 
} 
} 
void repuesto (tlista lis , long codigo ){
	if(lis!=NULL){
	    if(retorna_codigo(lis->dato)==codigo)
			mostrar_repuesto(lis->dato); 
		else 
			repuesto (lis->sig,codigo); 
	}
	else 
	   printf ("\nNo se encontro el Respuesto"); 
}
void modifica (tlista lis , long codi){
	if (lis!=NULL){
		if (retorna_codigo(lis->dato)==codi)
			modifica_precio(&lis->dato);
		else 
			modifica (lis->sig,codi);
	}
	else 
		printf ("\nCodigo ingresado no existe"); 
}
/**MODULOS PUBLICOS**/ 
tlista carga_lista (){
	tlista lis , nodo ; 
	int tam ; 
	lis=NULL ; 
	nodo=NULL ;
	printf ("\nIngrese el tamanio de la lista") ;
	scanf ("%d",&tam) ; 
	carga_rec (&lis,nodo,tam) ; 
	return lis ; 
}
void mostrar_lista (tlista lis){
	if (lis!=NULL){
		mostrar_repuesto (lis->dato); 
		mostrar_lista(lis->sig) ; 
	}
}
void datos_repuesto (tlista lis){
	long code ; 
	printf ("\nIngrese el codigo del repuesto: ");
	scanf ("%ld",&code); 
	repuesto (lis,code); 
}
void repuesto_no_disponibles (tlista lis ){
	if (lis!=NULL){
		if (retorna_cant(lis->dato)==0){
			mostrar_repuesto (lis->dato);
			repuesto_no_disponibles(lis->sig); 
		}
		else 
			repuesto_no_disponibles(lis->sig); 
	}
}
void agrega (tlista *lis){
	long code ; 
	tlista aux , ant , nodo ; 
	aux=*lis; 
	ant=NULL;
	code=codigo_valido(*lis) ; 
	nodo=crea_nodo(code) ; 
	agrega_ordenado (lis,aux,ant,nodo);
}
void modificar_precio (tlista lis ){
	long bus ; 
	printf ("\nIngrese el codigo del repuesto: ") ;
	scanf ("%ld",&bus);
	modifica (lis,bus); 
}
int valor (tlista lis ){
	if (lis==NULL)
		return 1 ; 
	else 
		return 0 ; 
}
void inicializa (tlista *lis){
	*lis=NULL; 
}
