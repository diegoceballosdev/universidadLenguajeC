#include <stdio.h>
#include <stdlib.h>

#include "RepuestosMotos.h"

int main (void){
	
	int op;
	long cod;
	TRrepuestos rep1, rep2, rep3;
	
	rep1 = cargarRepuesto();
	rep2 = cargarRepuesto();
	rep3 = cargarRepuesto();
	
	do{
		fflush(stdin);
		printf("\nPresione ENTER para mostrar opciones de Menu");
		getchar();
		system("cls");
		
		printf("\n ***** MENU *****");
		printf("\n Ingrese 0: Finalizar programa");
		printf("\n Ingrese 1: Mostrar repuesto con mayor stock disponible");
		printf("\n Ingrese 2: Modificar precio de un repuesto");
		printf("\n Ingrese su eleccion:");
		scanf("%d", &op);
		
		switch(op)
		{
		case 0: 
			printf("\n Adios"); 
			break;
		
		case 1:	 
			
			/*Si r1 es mayor que r2, solo resta comparar con r3*/
			if (comparaStock (rep1, rep2)==1){
				if (comparaStock (rep1, rep3)==1)
					mostrarRepuesto(rep1);
				else if (comparaStock (rep1, rep3)==-1)
					mostrarRepuesto(rep1);
				else{
					mostrarRepuesto(rep1);
					mostrarRepuesto(rep3);
				}
			}
			
			/*Si r1 es menor que r2, debo comparar r2 con r3*/
			else if (comparaStock (rep1, rep2)==-1){
				if (comparaStock (rep2, rep3)==1)
					mostrarRepuesto(rep2);
				else if (comparaStock (rep2, rep3)==-1)
					mostrarRepuesto(rep3);
				else{
					mostrarRepuesto(rep2);
					mostrarRepuesto(rep3);
				}
			}
			
			/*Como r1 no es mayor ni menor que r2, entonces son iguales*/		
			/*Entonces uso r1=r2 para comparar con r3*/
			else if (comparaStock (rep1, rep3)==1){
				/*Muestro r1 y r2 pues pues (r1=r2) > r3*/
				mostrarRepuesto(rep1);
				mostrarRepuesto(rep2);
			}
			
			/*Si r1=r2 es menor que r3:*/
			else if (comparaStock (rep1, rep3)==-1)
				mostrarRepuesto(rep3);
			
			/*La ultima posibilidad es r1=r2=r3*/
			else{
				mostrarRepuesto(rep1);
				mostrarRepuesto(rep2);
				mostrarRepuesto(rep3);
			}					
			break;
			
		case 2: 
			printf("\n Ingrese codigo del producto:");
			scanf("%ld", &cod);
			if (returnCod(rep1)==cod)
				modificarPrecio (&rep1);
			else if (returnCod(rep2)==cod)
				modificarPrecio (&rep2);
			else if (returnCod(rep3)==cod)
				modificarPrecio (&rep3);
			else 
				printf("El codigo ingresado no coincide con ningun producto");
			break;

		default: 
			printf("\nIngrese una opción correcta"); 
			break;
		}
	}while(op!=0);
		
	return 0;
}
	
