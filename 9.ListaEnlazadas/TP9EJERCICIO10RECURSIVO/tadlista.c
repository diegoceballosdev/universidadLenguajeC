#include "tadlista.h" 
/**MODULOS PRIVADOS**/ 
int verifica (tlista lis ,long bus){
	if (lis!=NULL){
		if (retorna_nro (lis->dato)==bus)
			return 1 ; 
		else 
			return verifica (lis->sig,bus) ; 
	}
	else 
		return -1 ;
}
long pedido_valido (tlista lis ,tlista lis2 ){
	long num ; 
	printf ("\nIngrese numero del pedido: ");
	scanf ("%ld",&num) ;
	if ( verifica(lis,num) ==-1){
		if (verifica(lis2,num)==-1)
			return num ; 
		else 
			return pedido_valido(lis,lis2);
	}
	else 
		return pedido_valido(lis,lis2); 
}
tlista crea_nodo(long nro){
	tlista nvo;
	nvo=(tlista)malloc(sizeof(tnodo));
	nvo->dato =carga_pedido(nro);
	nvo->sig=NULL;
	return nvo;
}
void agrega_cab(tlista *cab, tlista nodo){
	nodo->sig=*cab; 
	*cab=nodo ; 
}
void muestra_rec(tlista lis){
	if (lis!=NULL){
		mostrar_pedido(lis->dato);
		muestra_rec (lis->sig); 
	}
}
void agrega_otra_lista (tlista *cab , tlista *lis , tlista aux ,tlista ant , long nro){
	if (aux!=NULL){
		if (retorna_nro(aux->dato)==nro){
			if (ant==NULL){
				*cab=aux->sig ; 
				aux->sig=NULL ;
				agrega_cab(lis,aux); 
				aux=NULL ; 
				free(aux);
			}
			else {
				ant->sig=aux->sig ; 
				aux->sig=NULL ;
				agrega_cab(lis,aux); 
				aux=NULL; 
				free(aux);
			} 
	
		}
		else 
			agrega_otra_lista (cab,lis,aux->sig,aux,nro) ; 
	}
	else 
		printf ("\nNro de pedido no VALIDO "); 
	}

void control (tlista lis , long bus){
	if (lis!=NULL){
		if(retorna_fecha(lis->dato)==bus){
			mostrar_pedido(lis->dato); 
			control(lis->sig,bus); 
		}
		else 
		   control(lis->sig , bus); 
	}
}
/**MODULOS PUBLICOS**/ 
void agrega_pedido (tlista *lis , tlista lis2){
	tlista nvo ; 
	long nro ; 
	nro=pedido_valido(*lis,lis2); 
	nvo=crea_nodo (nro); 
	agrega_cab(lis,nvo); 
}
void resueltos (tlista *cab , tlista *lis){
	tlista ant , aux ; 
	long nro ; 
	ant=NULL; 
	aux=*cab ; 
	printf ("\nIngrese el nro del pedido: ") ;
	scanf ("%ld",&nro);
	agrega_otra_lista (cab,lis,aux,ant,nro); 
}
void mostrar_lista (tlista lis ){
	if (lis!=NULL){
		mostrar_pedido (lis->dato); 
		mostrar_lista (lis->sig); 
	}
}
void control_fecha (tlista lis ){
	long  bus ; 
	printf ("\nIngrese la fecha aaaammdd: ");
	scanf ("%ld",&bus);
	control (lis,bus); 
}
void inicializa (tlista *lis){
	*lis=NULL; 
}
int valor (tlista lis) {
	if (lis==NULL)
		return 1 ; 
	else 
		return 0; 
}
