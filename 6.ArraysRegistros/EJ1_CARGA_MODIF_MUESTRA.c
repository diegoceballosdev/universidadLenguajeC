/*EJEMPLO 1
Dada una lista de las notas de un parcial de N alumnos, de los cuales se almacena
la siguiente información:DNI,Nota obtenida, Apellido y Nombre. Se pide realizar
un programa que cargue la lista. Luego modifique la nota de un alumno, dado el DNI.
Al final muestre la lista. */

#include <stdio.h>
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
/* Modulos que trabajan sobre el registro alumno */
Talumno carga_alumno();
void muestra_alumno(Talumno);
void modificaNota(Talumno *,int);

/* Modulos que trabajan sobre la lista de alumnos */
void cargarLista(Tlista,int *);
void mostrarLista(Tlista,int );
int buscarPosAlumno(Tlista, int, long);

/* Modulo Cadena */
void leeCad(Tcadena, int);

/* Programa Principal */
int main(void) {
	int tam,p,nnota;
	long dni;
	Tlista Curso;
		
	/** CARGAR LISTA */	
	cargarLista(Curso,&tam);
	
	/** MODIFICAR NOTA - DADO DNI **/
	printf("\n\nIngrese el DNI a modifcar: ");
	scanf("%ld",&dni);
	p=buscarPosAlumno(Curso,tam,dni);
	if(p!= -1){
		printf("\n\nIngrese la nueva nota: ");
		scanf("%d",&nnota);
		modificaNota(&Curso[p],nnota);}
	else
		printf("\nNO existe en la lista el DNI ingresado");
	
	/** MOSTRAR LISTA */	
	if(tam!=0) {
		printf("\n\nlista Ingresada\n");
		mostrarLista(Curso, tam);
	}
	 else printf("lista Vacia\n");
	
	return 0;
}

/**** DEFINICIÓN DE MODULOS DE l REGISTRO   *****/
Talumno carga_alumno(){
	Talumno aux;
	printf("\nIngrese DNI del alumno: ");
	scanf("%ld",&aux.dni);
	printf("\nIngrese NOTA del alumno: ");
	scanf("%u",&aux.nota);
	printf("\nIngrese APELLIDO Y NOMBRE del alumno: ");
	fflush(stdin);
	leeCad(aux.ApellNom,MAX_CAD);
	return aux;	
}


void muestra_alumno(Talumno alu){
	printf("\nDNI: %ld",alu.dni);
	printf("\nNOTA: %u",alu.nota);
	printf("\nAPELLIDO Y NOMBRE: %s",alu.ApellNom);	
}

void modificaNota(Talumno *alu,int nn){
	alu->nota=nn;	
}

/**** DEFINICIÓN DE MODULOS DE LA LISTA  *****/

/** CARGA VECTOR DE REGISTROS  (Sin orden) */	
void cargarLista(Tlista lis,int *n){
	int i;
		
	printf("\nIngrese cantidad de elemento del vector: ");
	scanf("%d",n);
	
	for(i=1;i<=*n;i++)
		lis[i]=carga_alumno();
		
}

int buscarPosAlumno(Tlista l, int N, long dni1){
	int i;
		i=1;
		while (i<=N && l[i].dni != dni1) 
			i++;;
		if(i<=N) return i;
		else return -1;	
}
		
void mostrarLista(Tlista lis,int n){
	int i;
	for (i=1;i<=n;i++)
			muestra_alumno(lis[i]);
		
}
/*** 	DEFINICIÓN DE MODULOS DE CADENA  *****/
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
