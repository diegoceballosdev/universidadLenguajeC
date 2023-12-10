#include <stdio.h>
#include "TAD_ListaEmpleados.h"

void opciones();
void menu_recursivo(TLista *, TLista *);

int main(){
	TLista A, D;
	D=inicializa_lista();
	A= carga_empleados();
	ordenar_dni(&A);
	menu_recursivo(&A, &D);
	return 0;
}

void opciones(){
	printf("\n=======Menu de opciones========");
	printf("\nIngrese 1: agregar un nuevo empleado a la lista");
	printf("\nIngrese 2: eliminar un empleado de la lista");
	printf("\nIngrese 3: modificar los datos de un empleado de la lista");
	printf("\nIngrese 4: mostrar la lista");
	printf("\nIngrese 5: mostrar empleados por especialidad y horario solicitado");
	printf("\nIngrese 6: generar y mostrar una lista nueva por especialidad y estado libre");
	printf("\nIngrese 0: para salir del MENU");
}
void menu_recursivo(TLista *A, TLista *D){
	int rta;
	opciones();
	printf("\nIngrese su eleccion: ");
	scanf("%d", &rta);
	switch(rta){
		case 0: 
			printf("\nA elegido Salir del Programa"); 
			break;
		case 1: 
			if(retorna_tam(*A)<10){
				agrega_empleados(&*A);
				ordenar_dni(&*A);
			}
			else
				printf("\nNo se puede agregar un empleado, lista llena");
			menu_recursivo(A, D);	
			break;
		case 2: 
			if(retorna_tam(*A)>0)
				elimina_empleados(A);
			else 
				printf("\nNo se puede eliminar un empleado, lista vacia");
			menu_recursivo(A, D); 
			break;
		case 3: 
			if(retorna_tam(*A)>0){ 
				modifica_empleados(A);
				ordenar_dni(A);
			}
			else
				printf("\nNo se puede modificar un empleado, lista vacia");
			menu_recursivo(A, D);
			break;
		case 4: 
			if(retorna_tam(*A)>0){ 
				mostrar_empleados(*A);
				printf("\nSe mostro exitosamente la lista de empleado");
			}
			else
				printf("\nNo se puede mostrar la lista de empleado, lista vacia");
			menu_recursivo(A, D);	
			break;
		case 5: 
			if(retorna_tam(*A)>0){ 
				mostrar_esp_turno(*A);
				printf("\nSe mostro exitosamente los empleados disponibles");
			}
			else  
				printf("\nNo se puede mostrar empleados disponibles, lista vacia");
			menu_recursivo(A, D);		
			break;
		case 6: 
			if(retorna_tam(*A)>0){ 
				genera_esp_libre(*A, D);
				if(retorna_tam(*D)>0){ 
					mostrar_empleados(*D);
				}
				else  
					printf("\nNo se puede mostrar la lista nueva, lista vacia");
			}
			else  
				printf("\n lista vacia");
			menu_recursivo(A, D);		
			break;		
		default: 
			printf("\nA ingresado un valor no valido");
			menu_recursivo(A, D);
			break;
	}
}	
