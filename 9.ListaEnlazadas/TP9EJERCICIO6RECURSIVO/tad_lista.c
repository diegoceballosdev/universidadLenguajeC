#include "tad_lista.h"
/**MODULOS PRIVADOS**/ 
int validacion (tlista lis , int bus ){
	if (lis!=NULL){
		if(retorna_nro(lis->dato)==bus)
			return 1 ; 
		else 
			return validacion (lis->sig,bus); 
	}
	else 
		return -1 ; 
}
int nro_valido (tlista lis ){
	int nro ; 
	printf ("\nIngrese NRO de la habitacion: "); 
	scanf ("%d",&nro);  
	if (validacion(lis,nro)!=-1)
		return nro_valido (lis); 
	else 
		return nro; 
}
tlista crea_nodo (int nro ){
	tlista nvo ; 
	nvo=(tlista)malloc(sizeof(tnodo));
	nvo->dato=carga_reg(nro) ;
	nvo->sig=NULL; 
	return nvo ; 
}
void reserva (tlista lis , int nro){
	if ( lis!=NULL) {
		if (retorna_nro(lis->dato)==nro)
			mostrar_reg(lis->dato) ;
		else 
			reserva (lis->sig,nro) ; 
	}
	else 
		printf ("\nNRO ingresado no valido") ; 
}
void modif (tlista *lis , int nro ) {
	if (*lis!=NULL) {
		if (retorna_nro((*lis)->dato)==nro) 
			modif_reg (&(*lis)->dato) ; 
		else 
			modif (&(*lis)->sig , nro ) ;
	}
	else 
		printf ("\nNRO ingresado no valido") ;
}
/**MODULOS PUBLICOS**/ 
void inicializa (tlista *lis){
	*lis=NULL;
} 
void agrega (tlista *lis){
	int nro ;
	tlista nodo ; 
	nro=nro_valido (*lis); 
	nodo=crea_nodo(nro); 
	nodo->sig=*lis ; 
	*lis=nodo; 
}
void mostrar_lista (tlista lis) {
	if (lis!=NULL) {
		mostrar_reg (lis->dato) ; 
		mostrar_lista (lis->sig); 
	}
}
void mostrar_reserva (tlista lis ) {
	int nro ;
	printf ("\nIngrese el nro de la habitacion: "); 
	scanf ("%d",&nro); 
	reserva(lis,nro) ; 
}
void modif_lista (tlista *lis) {
	tlista aux ; 
	int nro ; 
	aux=*lis ; 
	printf ("\nIngrese el nro de la habitacion: ") ; 
	scanf ("%d",&nro) ; 
	modif (&aux,nro) ; 
}
int valor (tlista aux ){
	if (aux==NULL)
		return 1 ; 
	else 
		return 0 ; 
}
