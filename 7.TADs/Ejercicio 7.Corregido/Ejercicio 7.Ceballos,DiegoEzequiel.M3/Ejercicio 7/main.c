#include <stdio.h>
#include <stdlib.h>

#include "ListaRepuestos.h"

int main (void){
	
	int op, B;
	long cod;
	Tlista Lista;
	B=0;
	
	do{
		fflush(stdin);
		printf("\nPresione ENTER para mostrar opciones de Menu");
		getchar();
		system("cls");
		
		printf("\n ***** MENU *****");
		printf("\n Ingrese 0: Finalizar programa");
		printf("\n Ingrese 1: Cargar lista ordenada alfabeticamente");
		printf("\n Ingrese 2: Modificar nombre de un repuesto");
		printf("\n Ingrese 3: Mostrar lista ordenada alfabeticamente");
		printf("\n Ingrese su eleccion:");
		scanf("%d", &op);
		
		switch(op)
		{
		case 0: 
			printf("\n Adios"); 
			break;
			
		case 1:	
			if (B==0){
				Lista = inicializarLista();/** SE DEBERÍA INICIALIZAR/ CARGAR LISTA FUERA DEL CASE*/
				Lista = cargarListaOrdenada (&Lista);
			}
			else
				printf("\n La lista ya esta cargada");
			break;
			
		case 2: 
			printf("\n Ingrese codigo del repuesto a renombrar: ");
			scanf("%ld", &cod);
			modificarNombrePorCod (Lista, cod);
			break;
		
		case 3: 
			mostrarLisOrdAlf (Lista);
			break;
			
		default: 
			printf("\nIngrese una opción correcta"); 
			break;
		}
	}while(op!=0);
	
	return 0;
}
