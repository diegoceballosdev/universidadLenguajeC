#include <stdio.h>
#include "TAD_ListaMedicamentos.h"

void opciones();
void menu_recursivo(TLista *, TLista *);

int main(){
	TLista A, D;
	A=iniciliza_lista(); 
	D=iniciliza_lista();
	A=carga_medicamentos();
	menu_recursivo(&A, &D);
	return 0;
}

void opciones(){
	printf("\n=======Menu de opciones========");
	printf("\nIngrese 1: agregar un nuevo medicamento a la lista");
	printf("\nIngrese 2: eliminar un medicamento de la lista");
	printf("\nIngrese 3: modificar los datos de un medicamento de la lista");
	printf("\nIngrese 4: mostrar la lista");
	printf("\nIngrese 5: mostrar medicamentos vencidos");
	printf("\nIngrese 6: generar y mostrar (ordenada por laboratorio) una lista nueva por stock");
	printf("\nIngrese 0: para salir del MENU");
}
void menu_recursivo(TLista *A, TLista *D){
	int rta;		
	opciones();
	printf("\nIngrese su eleccion: ");
	scanf("%d", &rta);
	switch(rta){
	case 0: printf("\nA elegido Salir del Programa"); 
			break;
	case 1: if(retorna_tam(*A)<10)  agrega_medicamentos(A);
			else  printf("\nNo se puede agregar el medicamento, lista llena");
			menu_recursivo(A, D);		
			break;
	case 2: if(retorna_tam(*A)!=0){ 
				elimina_medicamentos(A);
			}
			else  printf("\nNo se puede eliminar el medicamento, lista vacia");
			menu_recursivo(A, D); 
			break;
	case 3: if(retorna_tam(*A)>0){ 
				modifica_medicamentos(A);
				printf("\nSe modifico exitosamente el medicamento");
			}
			else  printf("\nNo se puede modificar el medicamento, lista vacia");
			menu_recursivo(A, D);		
			break;
	case 4: if(retorna_tam(*A)>0){ 
				mostrar_medicamentos(*A);
				printf("\nSe mostro exitosamente la lista de medicamentos");
			}
			else  printf("\nNo se puede mostrar la lista de medicamentos, lista vacia");
			menu_recursivo(A, D);		
			break;
	case 5: if(retorna_tam(*A)>0){
				mostrar_lab_vto(*A);
				printf("\nSe mostro exitosamente los medicamentos vencidos");}
			else  printf("\nNo se puede mostrar medicamentos vencidos, lista vacia");
			menu_recursivo(A, D);		
			break;
	case 6: if(retorna_tam(*A)>0){ 
				genera_stock(*A, D);
				if(retorna_tam(*D)>0){
					ordenar_lab(D);
					mostrar_medicamentos(*D);
				}
				else printf("\n No se pudo generar la lista nueva");
			}
			else  printf("\nlista original vacia");
			menu_recursivo(A, D);		
			break;		
	default: printf("\nA ingresado un valor no valido");
			menu_recursivo(A, D);
			break;
	}
}	
	
