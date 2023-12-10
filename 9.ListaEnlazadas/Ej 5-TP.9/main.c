/*Ejercicio 5: Realizar la especificación y la implementación de los TADs 
que considere necesarios para resolver el siguiente problema.
Diseñar un programa que permita, a través de un menú de opciones, 
administrar una lista de alumnos, ordenada por DNI. 
Por cada alumno se registra: DNI, Apellido y Nombre del alumno, 
Condición (1: Regular / 2: Libre).
El programa debe permitir:
? agregar un alumno a la lista, manteniendo el órden;
? dado un DNI eliminarlo de la lista;
? dado un DNI mostrar los datos del alumno;
? mostrar la cantidad de regulares y libres;
? mostrar la lista completa.
Nota: La lista se genera a partir del menú, por lo que no hay 
una carga previa de la misma.*/
#include<stdio.h>
#include<stdlib.h>
#include "TADlista_enlazada.h"

void menu(int*);

int main (int argc, char *argv[]) {
	T_ptr A=NULL;
	int op;
	do{
		menu(&op);
		switch(op){
		case 1:
			agregar_uno_ordenado(&A);
			break;
		case 2:
			eliminar_unalumno(&A);
			break;
		case 3:
			mostrar_unalumno(A);
			break;
		case 4:
			cantidad_lyr(A);
			break;
		case 5:
			mostrar_lis_en(A);
			break;
		}
	} while(op!=0);
	
	return 0;
}

void menu(int *op){
	printf("\nOpcion 1: Para agregar un alumno");
	printf("\nOpcion 2: Para eliminar un alumno");
	printf("\nOpcion 3: Para mostrar los datos de un alumno segun el DNI");
	printf("\nOpcion 4: Para mostrar la cantidad de alumnos libres y regulares");
	printf("\nOpcion 5: Para mostrar todos los alumnos");
	printf("\nOpcion 0: Para salir");
	printf("\nIngrese opcion: ");
	scanf("%d",op);
	system("cls");
}
	


