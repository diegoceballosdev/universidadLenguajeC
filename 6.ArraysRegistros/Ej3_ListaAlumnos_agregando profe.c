/*EJEMPLO VECTOR DE REGISTRO SIN CARGA -CON AGREGAR EN MENU
Dada una lista de las notas de un parcial de N alumnos, de los cuales se almacena
la siguiente información:DNI,Nota obtenida, Apellido y Nombre. Se pide realizar
un programa que mediante un menú permita: 
- Agregar elementos a la lista (ordenados x DNI sin repetición)
- Mostrar lista completa */

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

typedef Talumno Tlista[MAX_VEC];   

/****    PROTOTIPOS   ****/
/** Modulos que trabajan sobre el registro alumno **/
Talumno carga_alumno(long); /* Carga datos del registro TAlumno - con dni validado*/
void muestra_alumno(Talumno);/* Muestra los datos del registro Talumno */ 
int compara_Regalumnoxdni(Talumno,Talumno); /* Compara campo dni de dos registros TAlumno*/
void cambiar_nota(Talumno *,int);/* Modifica el campo nota de un registro Talumno*/


/** Modulos que trabajan sobre la lista de alumnos **/

long validarDni(Tlista ,int );/* Función que valida que el dni no se repita*/
void insertar_lista(Tlista,int *);
void inserta_registro(Tlista,int *,int,Talumno );
int buscar_pos_alumno(Tlista, int, long);/* Busca posición de un registro Talumno según nro long dado*/
void mostrar_lista(Tlista,int );/* Muestra lista de registros Talumno */

/**  Otros **/
void leeCad(Tcadena, int);/* Ingreso de cadena*/

int menu(); /*Función que retorna la opción de menú ingresada por el usuario*/


/** Programa Principal **/
int main(void) {
	int tam, opcion;
	Tlista Curso;
		
	tam=0;
	do{
		printf("\n\n");
		system("pause");
		system("cls");
		opcion=menu();
		switch (opcion){	
		case 1:
			if(tam<MAX_VEC)
				insertar_lista(Curso,&tam);			
			else 
				printf("lista Completa- No sepuede agregar otro alumno\n");
			break;				
		case 2:
			if(tam>0){
				printf("\n\nlista Ordenada x DNI\n");
			    mostrar_lista(Curso, tam);}			
			else 
				printf("lista Vacia\n");
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
/*
// Se utiliza este módulo cuando se carga un Registro Talumno sin validar ningún campo
	
Talumno carga_alumno(){
	Talumno aux;
	long dv;
	printf("\nIngrese DNI del alumno: ");
	scanf("%ld",&aux.dni);
	printf("\nIngrese NOTA del alumno: ");
	scanf("%u",&aux.nota);
	printf("\nIngrese APELLIDO Y NOMBRE del alumno: ");
	fflush(stdin);
	leeCad(aux.ApellNom,MAX_CAD);
	return aux;	
}*/


int compara_Regalumnoxdni(Talumno a1,Talumno a2){
	if(a1.dni>a2.dni)
		return 1;
	else if(a1.dni<a2.dni)
		return -1;
	else
		return 0;	
}
int compara_alumnoxdni(Talumno a1,long d){
	if(a1.dni>d)
		return 1;
	else if(a1.dni<d)
		  return -1;
		else
			return 0;	
}
	
	
void muestra_alumno(Talumno alu){
	printf("\nDNI: %ld",alu.dni);
	printf("\nNOTA: %u",alu.nota);
	printf("\nAPELLIDO Y NOMBRE: %s",alu.ApellNom);		
}


/**** Lista de alumnos (Tlista ) *****/

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
		

void mostrar_lista(Tlista lis,int n){
	int i;
	if (n>=1)
		for (i=1;i<=n;i++)
			muestra_alumno(lis[i]);
		else
			printf("\n No hay elementos en la lista");
}

int buscar_pos_alumno(Tlista l, int N, long dni1){
	int ini,fin,med;
	ini=1;
	fin=N;
	med=(ini+fin)/2;
	while (ini<=fin &&compara_alumnoxdni(l[med],dni1)) { //l[med].dni != dni1){
		 if(l[med].dni< dni1)
			ini=med+1;
		 else fin=med-1;
		 med=(ini+fin)/2;
	}
	if(ini<=fin) return med;
	else return -1;	
	
}

void inserta_registro(Tlista l,int *n1,int p,Talumno alu){
	int i,M;
	M=*n1;
	for(i=M;i>=p;i--)
		l[i+1]=l[i];
	l[p]=alu;	
	*n1=M+1;
}
void insertar_lista(Tlista lis,int *n){
	Talumno nue;
	int i;
	long doc;
	printf("\n Ingrese los datos del alumno a agregar");
	doc=validarDni(lis,*n);
	nue=carga_alumno(doc);
	i=1;
	while(i<=*n && compara_Regalumnoxdni(lis[i],nue)!=1)
		i=i+1;
	inserta_registro(lis,n,i,nue);
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
	int op;
	printf("\n ********  Menu  ********\n");
	printf("\n 1 - Agregar un Alumno");	
	printf("\n 2 - Mostrar Lista");	
	printf("\n 0 - Salir \n");
	printf("\n Ingrese opcion: ");
	scanf("%d",&op);
	return op;	
}
