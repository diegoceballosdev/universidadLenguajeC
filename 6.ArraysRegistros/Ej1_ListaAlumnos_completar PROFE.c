/* EJERCICIO CON MENU -COMPLETAR 
Dada una lista de las notas de un parcial de N alumnos, de los cuales se almacena
la siguiente información:DNI,Nota obtenida, Apellido y Nombre. Se pide realizar
un programa que permita realizar la carga de una lista ordenada por dni y 
luego mediante un menú:
a) Permita modificar la nota de un alumno, dado su DNI.
b) Eliminar un alumno.
c) Mostrar la lista completa

¿¿¿ opcion para insertar un alumno preservando el orden??? */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_CAD 50
#define MAX_VEC 40

typedef char Tcadena[MAX_CAD];
typedef struct {
	long dni;
	unsigned nota;
	Tcadena ApellNom;	
}Talumno;

typedef Talumno Tlista[MAX_VEC];   /*  o Talumno Tlista[40];*/

/****    PROTOTIPOS   ****/
/** Modulos que trabajan sobre el registro alumno **/
Talumno carga_alumno(long); /* Carga datos del registro TAlumno - con dni validado*/
void muestra_alumno(Talumno);/* Muestra los datos del registro Talumno */ 
int compara_Regalumnoxdni(Talumno,Talumno); /* Compara campo dni de dos registros TAlumno*/
int compara_alumnoxdni(Talumno,long);/* Compara campo dni de un registro Talumno con un nro long dado*/
void cambiar_nota(Talumno *,int);/* Modifica el campo nota de un registro Talumno*/


/** Modulos que trabajan sobre la lista de alumnos **/
void cargar_vec_ordenado(Tlista,int *);/* carga lista de registros Talumno ordenada*/
long validarDni(Tlista ,int );/* Función que valida que el dni no se repita*/
void inserta_ordenado(Tlista ,int ,Talumno);/* Inserta registro Talumno por inserción directa*/
void mostrar_lista(Tlista,int );/* Muestra lista de registros Talumno */
int buscar_pos_alumno(Tlista, int, long);/* Busca posición de un registro Talumno según nro long dado*/
void modificar_nota(Tlista, int);/* Modifica la nota de un registro de la lista, dado un dni*/
void elimina_alumno_dni(Tlista,int *);/* Elimina un registro de la lista, dado un dni*/
void elimina_registro(Tlista, int *, int);/*Elimina un registro de la lista, de una determinada posición*/

/**  Otros **/
void leeCad(Tcadena, int);/* Ingreso de cadena*/

int menu(); /*Función que retorna la opción de menú ingresada por el usuario*/


/** Programa Principal **/
int main(void) {
	int tam, opcion;
	Tlista Curso;
		
	cargar_vec_ordenado(Curso,&tam);
	do{
		printf("\n\n");
		system("pause");
		system("cls");
		opcion=menu();
		switch (opcion){	
		case 1: 
			if(tam>0)
				 modificar_nota(Curso,tam);
			 else 
				 printf("lista Vacia\n");
			break;
		case 2: 
			if(tam>0)
				elimina_alumno_dni(Curso,&tam);			
			 else 
				 printf("lista Vacia\n");
			break;	
		case 3:
			/**COMPLETAR*/
			break;				
		default:
			if(opcion!=0)
				printf("Ingreso opcion incorrecta\n");			
		}
	}while(opcion!=0);
	
	return 0;
}

/**** DEFINICIÓN DE LOS MODULOS   *****/

/** Registro Talumno **/
Talumno carga_alumno(long d){
	Talumno aux;
	
	aux.dni=d;
	printf("\nIngrese NOTA del alumno: ");
	scanf("%u",&aux.nota);
	printf("\nIngrese APELLIDO Y NOMBRE del alumno: ");
	fflush(stdin);
	leeCad(aux.ApellNom,MAX_CAD);
	return aux;	
}	

int compara_Regalumnoxdni(Talumno a1,Talumno a2){
	/** COMPLETAR*/	
}
int compara_alumnoxdni(Talumno a1,long d){
	if(a1.dni>d)
		return 1;
	else if(a1.dni<d)
		  return -1;
		else
			return 0;	
	}
	
void cambiar_nota(Talumno *a1,int n){	
	/** COMPLETAR */		
}
		
void muestra_alumno(Talumno alu){
	printf("\nDNI: %ld",alu.dni);
	printf("\nNOTA: %u",alu.nota);
	printf("\nAPELLIDO Y NOMBRE: %s",alu.ApellNom);	
}


/**** Lista de alumnos (Tlista ) *****/

void cargar_vec_ordenado(Tlista lis,int *n){
	int i,j;
	long doc;
	Talumno aux;
		
	printf("\nIngrese cantidad de elemento del vector: ");
	scanf("%d",n);		
	for(i=1;i<=*n;i++){
		doc=validarDni(lis,*n);
		aux=carga_alumno(doc);
		j=i-1;
		inserta_ordenado(lis,j,aux);		
	}	
}
long validarDni(Tlista l1,int n1){
	int p;long d;
	do{
		printf("\nIngrese DNI del alumno: ");
		scanf("%ld",&d);
		p=buscar_pos_alumno(l1,n1,d);
		if (p!= -1)
			printf("\nEl DNI ingresado ya existe");
		}while (p!=-1);
		return d;
}
		
void inserta_ordenado(Tlista lis,int j1,Talumno alu){
	while(j1>0&& compara_Regalumnoxdni(alu,lis[j1])==-1){
		lis[j1+1]=lis[j1];
		j1--;
	}
	lis[j1+1]=alu;	
}
			
void mostrar_lista(Tlista lis,int n){
	/** COMPLETAR*/
}

int buscar_pos_alumno(Tlista l, int N, long dni1){
	int ini,fin,med;
	ini=1;
	fin=N;
	med=(ini+fin)/2;
	while (ini<=fin &&compara_alumnoxdni(l[med],dni1)) {      //l[med].dni != dni1){
		 if(l[med].dni< dni1)
			ini=med+1;
		 else fin=med-1;
		 med=(ini+fin)/2;
	}
	if(ini<=fin) return med;
	else return -1;	
	
}

/** Eliminar un registro de la lista **/	
void elimina_registro(Tlista l, int *N, int pos){
	/**COMPLETAR*/	
}
			
/** Eliminar un alumno - Dado DNI*/
void elimina_alumno_dni(Tlista lis,int *n){
	int pos;
	long doc;	
	printf("\nIngrese el DNI del alumno a eliminar: ");
	scanf("%ld",&doc);
	pos=buscar_pos_alumno(lis, *n, doc);/* se podria mejorar la interface??*/
	if (pos>0)
	   elimina_registro(lis,n,pos);
	else
		printf("\nNo existe alumno con el dni ingresado");
}
	
void modificar_nota(Tlista lis, int n){
	int nota,pos;
	long dni;
	printf("\n\nIngrese el DNI del alumno a modificar\n");
	scanf("%ld",&dni);
	pos=buscar_pos_alumno(lis,n,dni);
	if(pos!=-1){
		printf("\n\nIngrese la nueva nota del alumno a modificar\n");/* se podria mejorar la interface??*/
		scanf("%d",&nota);
		cambiar_nota(&lis[pos],nota);
	}
	else
		printf("\n\nNO existe alumno con DNI ingresado\n");
}				
/** MODULOS CADENA **/				
	void leeCad(char * cadena, int tam){
		int j;
		char c;
		j=0;
		c=getchar();			
		while (c!=EOF && c!='\n' && j<tam-1)
		{
			cadena[j]=c;
			j++;
			c=getchar();
		}
		cadena[j]='\0';
		
		while(c!=EOF && c!='\n')
			c=getchar();
	}	
/** MENU **/
		
int menu(){
	/**COMPLETAR */
}
