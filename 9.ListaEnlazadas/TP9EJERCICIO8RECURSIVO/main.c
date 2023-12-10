#include "tadlista.h"
void opciones (); 
void menu (tlista *);
int main(){
	tlista repuestos  ;
	inicializa (&repuestos) ; 
	repuestos=carga_lista(); 
	menu (&repuestos); 
	return 0; 
}
void opciones (){
	printf ("\n====OPCIONES DEL MENU====");
	printf ("\nINGRESE 0: SALIR DEL MENU");
	printf ("\nINGRESE 1: MOSTRAR LISTA ");
	printf ("\nINGRESE 2: MOSTRAR REPUESTO");
	printf ("\nINGRESE 3: MODIFICA PRECIO DE UN REPUESTO"); 
	printf ("\nINGRESE 4: REPUESTO NO DISPONIBLES"); 
	printf ("\nINGRESE 5: AGREGA REPUESTO"); 
}
void menu (tlista *lis){
	int rta ; 
	opciones(); 
	printf ("\nINGRESE SU ELECCION: ");
	scanf ("%d",&rta);
	switch (rta){
	case 0:
		printf ("\nFIN DEL PROGRAMA"); 
		break ; 
	case 1:
		if (valor(*lis)==0)
			mostrar_lista(*lis); 
		else 
			printf ("\nLISTA VACIA"); 
		menu (lis); 
		break; 
	case 2: 
		if (valor(*lis)==0)
			datos_repuesto(*lis);
		else 
			printf ("\nLISTA VACIA"); 
		menu (lis); 
		break ; 
	case 3: 
		if (valor(*lis)==0)
			modificar_precio(*lis); 
		else 
			printf ("\nLISTA VACIA"); 
		menu (lis);
		break ; 
	case 4 :
		if (valor(*lis)==0)
			repuesto_no_disponibles (*lis); 
		else 
			printf ("\nLISTA VACIA");
		menu (lis) ; 
		break; 
	case 5: 
		agrega (lis); 
		menu (lis) ;
		break ; 
	default :
		printf ("\nOPCION NO VALIDA") ; 
		menu (lis); 
	}
}
