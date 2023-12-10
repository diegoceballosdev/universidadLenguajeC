#include "tad_registro.h" 
treg carga_articulo (long codigo) {
	treg aux ; 
	aux.code = codigo ; 
	printf ("\nIngrese el nombre del articulo: ");
	fflush(stdin);
	ing_nomb (aux.nombre) ; 
	printf ("\nIngrese el precio del articulo: ") ; 
	scanf ("%f",&aux.precio) ; 
	printf ("\nIngrese el stock del articulo: ");
	scanf ("%d",&aux.stock);
	return aux ; 
} 
void mostrar_articulo (treg art ){
	printf ("\n-----DATOS DEL ARTICULO-----\n") ; 
	printf ("\nCODIGO: %ld",art.code) ; 
	printf ("\nNOMBRE: %s",art.nombre); 
	printf ("\nPRECIO: %f",art.precio) ; 
	printf ("\nSTOCK: %d",art.stock); 
}
void modifica_articulo (treg*art,long codigo ){
	treg nvo ;
	mostrar_articulo(*art) ; 
	printf ("\n----MODIFIQUE LOS DATOS----" ) ;
	nvo=carga_articulo(codigo) ; 
	*art=nvo ; 
}
int compara_cad (treg art , tcad nomb ){
    return compara_cadenas (art.nombre,nomb); 
}
int retorna_stock (treg art ){
    return art.stock  ;
}
long retorna_code (treg art ){
	return art.code ; 
}
