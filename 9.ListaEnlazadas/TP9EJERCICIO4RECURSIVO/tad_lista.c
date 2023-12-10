#include "tad_lista.h" 
/**MODULOS PRIVADOS**/ 
int valida (tlista lis , long codigo ){
	if (lis!=NULL){
		if (retorna_code(lis->dato)==codigo) 
			return 1 ; 
		else 
			return valida (lis->sig , codigo) ; 
	}
	else 
		return -1 ; 
}
long code_valido (tlista lis){
	long codigo ;
	printf ("\nIngrese el codigo: ") ; 
	scanf ("%ld",&codigo) ; 
	if (valida(lis,codigo)!=1) 
		return codigo ; 
	else 
		return code_valido (lis) ; 
}
tlista crea_nodo (long code ){
	tlista nvo ; 
	nvo=(tlista)malloc(sizeof(tnodo)); 
	nvo->dato=carga_articulo(code) ; 
	nvo->sig= NULL; 
	return nvo ;
}
void agrega_ordenado (tlista *lis , tlista aux , tlista ant , tlista nodo ){
	if (aux!=NULL){
		if (retorna_code(aux->dato)<retorna_code(nodo->dato))
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
	long code ; 
	if (tam>0){
		code=code_valido(*lis) ; 
		nodo=crea_nodo(code) ;
		aux=*lis ; 
		agrega_ordenado (lis,aux,ant,nodo); 
		carga_rec (lis,nodo,tam-1); 
	} 
} 
void eliminar (tlista *lis, tlista aux , tlista ant , tcad nombre ){
	if (aux!=NULL){
		if (compara_cad(aux->dato,nombre)==0){
			if (ant==NULL){
				*lis=aux->sig ; 
				aux=NULL; 
				printf ("\nARTICULO ELIMINADO");
				free(aux); 
			}
			else{
				ant->sig=aux->sig ; 
				aux->sig=NULL ; 
				printf ("\nARTICULO ELIMINADO");
				free(aux); 
			}
		}
		else 
			eliminar (lis,aux->sig,aux,nombre);
	}
	else 
		printf ("\nEl articulo a eliminar no se encontro"); 
}
void modifica (tlista lis , long codigo ){
	if (lis!=NULL){
		if(retorna_code(lis->dato)==codigo)
			modifica_articulo(&lis->dato,codigo);
		else 
			modifica (lis->sig,codigo);
	}
	else 
		printf ("\nNo se encontro el articulo a modificar") ; 
}
int lista_tamanio (tlista lis ){
	if (lis!=NULL)
		return 1 + lista_tamanio (lis->sig);
	else 
		return 0; 
}
int stock_promedio (tlista lis){
	if (lis!=NULL)
		return retorna_stock (lis->dato)+stock_promedio (lis->sig) ;
	else 
		return 0 ; 
}
void mostrar_prom (tlista lis , int k ){
	if (lis!=NULL){
		if (retorna_stock(lis->dato)<k){
			mostrar_articulo (lis->dato); 
			mostrar_prom (lis->sig,k);
		}
		else 
			mostrar_prom(lis->sig,k);
	}
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
void mostrar_lista (tlista lis ){
	if (lis!=NULL){
		mostrar_articulo (lis->dato);
		mostrar_lista (lis->sig); 
	}	
}
void elimina_uno (tlista *lis){
	tlista aux , ant ; 
	tcad nombre ; 
	aux=*lis ; 
	ant=NULL ; 
	printf ("\nIngrese el nombre del articulo a eliminar: "); 
	fflush(stdin) ; 
	ing_nomb(nombre) ; 
	fflush(stdin); 
	eliminar (lis,aux,ant,nombre); 
}
void agrega (tlista *lis){
	long code ; 
	tlista aux , ant , nodo ;
	ant=NULL; 
	aux=*lis ; 
	code=code_valido(*lis); 
	nodo=crea_nodo(code); 
	agrega_ordenado (lis,aux,ant,nodo); 
}
void cambia_articulo (tlista lis){
	long codigo ; 
	printf ("\nIngrese el codigo del articulo a modificar ");
	scanf ("%ld",&codigo);
	modifica (lis,codigo); 
}
void random_prom (tlista lis){
	int k , prom ; 
	prom = stock_promedio (lis)/ lista_tamanio (lis); 
	k=rand()%((2*prom)-prom+1)+prom ; 
	mostrar_prom (lis,k); 
}
int valor (tlista aux ){
	if (aux==NULL)
		return 1;
	else 
		return 0; 
}
void inicializa (tlista *lis){
	*lis=NULL; 
}
