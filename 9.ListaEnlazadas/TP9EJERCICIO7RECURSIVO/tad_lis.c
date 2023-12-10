#include "tad_lis.h"
/**MODULOS PRIVADOS**/
int verifica (Tlista lis ,long bus){
	if (lis!=NULL){
		if (retorna_dni(lis->dato)==bus)
			return 1 ; 
		else 
			return verifica (lis->sig,bus) ; 
	}
	else 
		return -1 ;
}
long doc_valido (Tlista lis ){
	long doc ; 
	printf ("\nIngrese el Dni: ");
	scanf ("%ld",&doc) ; 
	if (verifica(lis,doc)!=-1){
		return doc_valido(lis); 
	}
	else 
		return doc ; 
}
Tlista crea_nodo(long doc){
	Tlista nvo;
	nvo=(Tlista)malloc(sizeof(Tnodo));
	nvo->dato =carga_alumno(doc);
	nvo->sig=NULL;
	return nvo;
}
void agrega_cab(Tlista *cab, Tlista nodo){
	nodo->sig=*cab; 
	*cab=nodo ; 
	}
void agrega_nodo (Tlista *lis , Tlista aux , Tlista ant , Tlista nodo){
	if (aux!=NULL){
		if (retorna_dni(aux->dato)<retorna_dni(nodo->dato))
			agrega_nodo (lis,aux->sig,aux,nodo) ; 
		else 
			if (ant==NULL)
				agrega_cab(lis,nodo);
			else {
				ant->sig=nodo; 
				nodo->sig=aux ; 
			}
	}
	else 
		ant->sig=nodo ; 
}
void muestra_rec(Tlista lis){
	if (lis!=NULL){
		muestra_alumno(lis->dato);
		muestra_rec (lis->sig); 
	}
}
void muestra_dato (Tlista lis , long doc ){
	if (lis!=NULL){
		if (retorna_dni(lis->dato)==doc)
		   muestra_alumno (lis->dato); 
		else 
			muestra_dato(lis->sig,doc); 
	}
	else 
		printf ("\nEl DNI no existe"); 
}
void Elimina_rec(Tlista *lis,Tlista aux , Tlista ant , long doc ){
	if (aux!=NULL){
		if (retorna_dni(aux->dato)==doc){
			if (ant==NULL){
				*lis=aux->sig ;
				aux=NULL ; 
				printf ("\nALUMNO ELIMINADO"); 
				free (aux); 
			}
			else {
				ant->sig=aux->sig;
				aux->sig=NULL; 
				printf ("\nALUMNO ELIMINADO") ;
				free (aux) ;
			}
		}
		else 
			Elimina_rec (lis,aux->sig,aux,doc); 
	}
	else 
		printf ("\nDni no encontrado"); 
}
/**MODULOS PUBLICOS**/ 
void agrega_alumno(Tlista *lis){
	Tlista nvo , aux , ant ;
	long doc;
	aux=NULL ; 
	ant=NULL ; 
	doc=doc_valido(*lis) ;
	nvo=crea_nodo(doc);
	if (*lis!=NULL){
	aux=*lis ; 
	agrega_nodo(lis,aux,ant,nvo);
	}
	else 
	   *lis=nvo ; 
} 
void Muestra_Lista(Tlista lis){
	if (lis!=NULL)	{
		muestra_rec (lis); 
	}
	else
		printf("\n Lista vacia");
}
void MuestraAlumno(Tlista lis){
	long doc ;
	if (lis!=NULL){	
		printf ("\nIngrese el DNI del alumno: ");
	    scanf ("%ld",&doc);
		muestra_dato(lis,doc); }
	else	 
		printf("\nLista vacia");
}
void Eliminar_Alumno(Tlista *lis){
	Tlista ant , aux ; 
	long doc;
	aux=NULL ; 
	ant=NULL ; 
	if (*lis!=NULL){
		printf("\nIngrese DNI: ");
		scanf("%ld", &doc);
		aux=*lis ;
		Elimina_rec(lis, aux , ant , doc);
	}
	else 
		printf ("\nLista Vacia") ; 
}
void inicializa (Tlista *alu ){
	*alu=NULL ; 
}
