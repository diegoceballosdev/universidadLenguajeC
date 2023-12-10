#include "tadlista.h"
void opciones (); 
void menu (tlista*,tlista*) ; 
int main (){
	tlista pedidos , resueltos ;
	inicializa (&pedidos); 
	inicializa (&resueltos); 
	menu (&pedidos , &resueltos); 
	return 0; 
}
void opciones (){
	printf ("\n====MENU====") ; 
	printf ("\nINGRESE 0: SALIR"); 
	printf ("\nINGRESE 1: AGREGA PEDIDO");
	printf ("\nINGRESE 2: AGREGA PEDIDO RESUELTO"); 
	printf ("\nINGRESE 3: PEDIDOS NO RESUELTOS "); 
	printf ("\nINGRESE 4: CONTROL DE PEDIDOS RESUELTOS"); 
	printf ("\nINGRESE 5: PEDIDOS RESUELTOS"); 
}
void menu (tlista *lis , tlista *lis2){
	int rta ; 
	opciones (); 
	printf ("\nINGRESE SU ELECCION"); 
	scanf ("%d",&rta); 
	switch (rta){
	case 0:
		printf ("\nFIN DEL PROGRAMA");
		break ; 
	case 1 :
		agrega_pedido (lis,*lis2);
		menu(lis,lis2); 
		break; 
	case 2: 
		if (valor(*lis)==0)
			resueltos(lis,lis2);
		else 
			printf ("\nLISTA DE PEDIDOS VACIA"); 
		menu (lis,lis2);
		break ; 
	case 3: 
		if (valor(*lis)==0)
			mostrar_lista (*lis) ; 
		else 
			printf ("\nLISTA DE PEDIDOS VACIA");
		menu (lis,lis2);
		break;
	case 4: 
		if(valor(*lis2)==0)
			control_fecha(*lis2);
		else 
			printf ("\nLISTA DE RESUELTOS VACIA"); 
	    menu (lis,lis2); 
		break;
	case 5: 
		if (valor(*lis2)==0)
			mostrar_lista(*lis2); 
		else 
			printf ("\nLISTA DE RESUELTOS VACIA"); 
		menu (lis,lis2);
		break ; 
	default: 
		printf ("\nOPCION INGRESA NO VALIDA "); 
		menu (lis,lis2); 
		
	}
}
