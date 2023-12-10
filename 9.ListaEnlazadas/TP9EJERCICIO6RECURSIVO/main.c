#include "tad_lista.h" 
void opciones () ; 
void menu (tlista*) ; 
int main (){
	tlista lis ; 
	inicializa (&lis); 
	menu (&lis) ; 
	return 0 ; 
}
void opciones (){
	printf ("\n====OPCIONES DEL MENU====") ;
	printf ("\nINGRESE 0:SALIR DEL MENU");
	printf ("\nINGRESE 1:AGREGE RESERVA");
	printf ("\nINGRESE 2:MOSTRAR DATOS DE LA RESERVA");
	printf ("\nINGRESE 3:MOSTRAR LISTA");
	printf ("\nINGRESE 4:MODIFICAR RESERVA"); 
		
}
void menu (tlista *lis){
	int rta ; 
	opciones () ; 
	printf ("\nINGRESE SU ELECCION: ");
	scanf ("%d",&rta); 
	switch (rta){
	case 0 : 
		printf ("\nFIN DEL PROGRAMA") ;
		break ; 
		case 1: 
		agrega(lis); 
		menu (lis); 
		break ; 
	case 2: 
		if (valor(*lis)==0)
		mostrar_reserva (*lis);
		else 
			printf ("\nLISTA VACIA"); 
		menu (lis); 
		break;
	case 3:
		if (valor (*lis)==0)
		mostrar_lista (*lis);
		else 
			printf ("\nLISTA VACIA") ;
		menu (lis); 
		break ;
	case 4: 
		if (valor(*lis)==0)
	    modif_lista(lis);
		else 
			printf ("\nLISTA VACIA"); 
		menu(lis); 
		break ; 
	default:
		printf ("\nOpcion inexistente");
		menu(lis); 
				
	}
}
			
