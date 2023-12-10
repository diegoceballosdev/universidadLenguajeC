#include "tad_lista.h"
void opciones () ; 
void menu_recu  (tlista*) ; 
int main (){
	tlista articulos ; 
	inicializa (&articulos) ; 
	articulos=carga_lista() ; 
	menu_recu(&articulos); 
	return 0; 
}
void opciones (){
	printf ("\n====MENU DE OPCIONES====\n" ) ;
	printf ("\nINGRESE 0: SALIR DE MENU ") ;
	printf ("\nINGRESE 1: AGREGA ARTICULO ") ;
	printf ("\nINGRESE 2: MODIFICA ARTICULO  ") ;
	printf ("\nINGRESE 3: ELIMINA ARTICULO ") ;
	printf ("\nINGRESE 4: PROMEDIO K DE  ARTICULO ") ;
	printf ("\nINGRESE 5: MOSTRAR LISTA ") ;
}
void menu_recu (tlista *lis){
	int rta ; 
	opciones (); 
	printf ("\nINGRESE SU ELECCION: ");
	scanf ("%d",&rta)  ; 
	switch (rta){
	case 0 : 
		printf ("\nFIN DEL PROGRAMA"); 
		break ; 
	case 1:
		agrega(lis); 
		menu_recu(lis) ;  
		break ; 
	case 2 :
		if (valor(*lis)==0)
			cambia_articulo(*lis); 
		else 
			printf ("\nLISTA VACIA"); 
		menu_recu(lis) ; 
		break ; 
	case 3: 
		if (valor(*lis)==0)
			elimina_uno(lis); 
		else 
			printf ("\nLISTA VACIA"); 
		menu_recu(lis);
		break ; 
	case 4:
		if (valor(*lis)==0)
			random_prom (*lis);
		else 
			printf ("\nLISTA VACIA"); 
		menu_recu(lis);
		break ;
	case 5:
		if (valor(*lis)==0)
			mostrar_lista (*lis);
		else 
			printf ("\nLISTA VACIA"); 
		menu_recu(lis); 
		break ; 
	default : 
		printf ("\nOpcion inexistente ");
		menu_recu(lis);
	}	
}
