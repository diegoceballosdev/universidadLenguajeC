#include "tadregistro.h"
/**MODULOS PUBLICOS**/ 
treg carga_repuesto (long code){
	treg aux ; 
	aux.codigo=code ; 
	printf ("\nIngrese el nombre del repuesto: ") ; 
	fflush (stdin) ; 
	leecad(aux.nombre) ;  
	fflush (stdin) ; 
	printf ("\nIngrese el precio del repuesto: ");
	scanf ("%f",&aux.precio) ; 
	printf ("\nIngrese la cantidad disponible: ")  ;
	scanf ("%d",&aux.cantidad);
	return aux ; 
}
void mostrar_repuesto (treg r){
	printf ("\n====DATOS DEL REPUESTO====") ;
	printf ("\nNOMBRE DEL REPUESTO: %s",r.nombre) ; 
	printf ("\nCODIGO: %ld",r.codigo) ;
	printf ("\nPRECIO UNITARIO: %f",r.precio);
	printf ("\nCANTIDAD DISPONIBLE: %d",r.cantidad);
	}
void modifica_precio (treg *r){
	float x ; 
	mostrar_repuesto (*r); 
	printf ("\nIngrese nuevo precio ") ;
	scanf ("%f",&x);
	r->precio=x ; 
}

long retorna_codigo (treg v ){
	return v.codigo ; 
}
int retorna_cant (treg v ) {
	return v.cantidad ;
}
