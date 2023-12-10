#include "tad_reg.h"
/**MODULOS PRIVADOS**/ 
/**MODULOS PUBLICOS**/
treg carga_reg (int nro){
	treg aux ; 
	aux.nro=nro ;
	do {
		printf ("\nINGRESE 1[SINGLE] 2[DOBLE] 3[TRIPLE] 4[CUADRUPLE]") ;
		printf ("\nINGRESE SU ELECCION: ");
		scanf ("%d",&aux.tipo) ; 
	}while (aux.tipo<1 || aux.tipo>4) ; 
	printf ("\nDNI: "); 
	scanf ("%ld",&aux.dni);
	printf ("\nAPELLIDO Y NOMBRE: ") ;
	fflush(stdin) ; 
	leecad(aux.ApeNom) ; 
	return aux ; 
}
void mostrar_reg (treg aux){
	tcad tip ;
	switch (aux.tipo){
		case 1:
			strcpy (tip, "SINGLE") ; 
			break ; 
		case 2: 
			strcpy (tip, "DOBLE");
			break ; 
		case 3: 
			strcpy (tip,"TRIPLE") ; 
			break ; 
		case 4: 
			strcpy (tip,"CUADRUPLE"); 
			break ; 
	}
	printf ("\n====DATOS DE LA RESERVA====");
	printf ("\nNRO: %d TIPO: %s DNI: %ld APELLIDO Y NOMBRE: %s ",aux.nro , tip , aux.dni , aux.ApeNom ); 
	}
void modif_reg (treg *aux){
	mostrar_reg (*aux) ; 
	printf ("\nINGRESE EL NUEVO TIPO");
	do {
		printf ("\nINGRESE 1[SINGLE] 2[DOBLE] 3[TRIPLE] 4[CUADRUPLE]") ;
		printf ("\nINGRESE SU ELECCION: ");
		scanf ("%d",&aux->tipo) ; 
	}while (aux->tipo<1 || aux->tipo>4) ; 
		}
int retorna_nro (treg aux){
    return aux.nro ; 
}
