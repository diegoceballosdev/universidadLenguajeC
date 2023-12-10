/*EJEMPLO VECTOR DE REGISTRO CON CAMPO CADENA - CARGA ORDENADA - SIN MENU
Dada una lista de las notas de un parcial de N alumnos, de los cuales se almacena
la siguiente información:DNI,Nota obtenida, Apellido y Nombre. Se pide realizar
un programa que cargue una lista ordenada por dni y muestre la lista ingresada */

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
Talumno carga_alumno();/* carga el registro */
void muestra_alumno(Talumno);/* muestra los datos del registro */
int compara_alumnoxdni(Talumno,Talumno);/* compara el campo DNI de dos registros */

/* Modulos que trabajan sobre la lista de alumnos */
void mostrar_lista(Tlista,int );/* muestra la lista de registros */
void cargar_vec_ordenado(Tlista,int *);/* cargar vector de registros ordenado x dni */
void inserta_ordenado(Tlista ,int ,Talumno);/* inserta un registro ordenado x DNI */

/* Modulo Cadena */
void leeCad(Tcadena, int);

/* Programa Principal */
int main(void) {
	int tam;
	Tlista Curso;
	
	/** CARGAR LISTA ORDENADA*/	
	cargar_vec_ordenado(Curso,&tam);
	
	/** MOSTRAR LISTA */	
	if(tam!=0){
		printf("\n\nlista Ordenada x DNI\n");
		mostrar_lista(Curso, tam);
	}
	  else printf("lista Vacia\n");
	
	return 0;
}

/**** DEFINICIÓN DE MODULOS DEl REGISTRO   *****/
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

int compara_alumnoxdni(Talumno a1,Talumno a2){
	if(a1.dni>a2.dni)
		return 1;
	else if(a1.dni<a2.dni)
		return -1;
	else
		return 0;	
}

void muestra_alumno(Talumno alu){
	printf("\nDNI: %ld",alu.dni);
	printf("\nNOTA: %u",alu.nota);
	printf("\nAPELLIDO Y NOMBRE: %s",alu.ApellNom);	
}


/**** DEFINICIÓN DE MODULOS DE LA LISTA  *****/

/*   INSERTA ORDENADO  */
void inserta_ordenado(Tlista lis,int j1,Talumno alu){
	int j;
	j=j1;
	while(j>0&& compara_alumnoxdni(alu,lis[j])==-1){
		lis[j+1]=lis[j];
		j--;}
	lis[j+1]=alu;	
}
	
/** CARGA VECTOR DE REGISTROS  (ordenado) */	
void cargar_vec_ordenado(Tlista lis,int *n){
	int i,j;
	Talumno aux;
	
	printf("\nIngrese cantidad de elemento del vector: ");
	scanf("%d",n);	
	for(i=1;i<=*n;i++){
		aux=carga_alumno();
		j=i-1;
		inserta_ordenado(lis,j,aux);		
	}	
}
	
void mostrar_lista(Tlista lis,int n){
	int i;
	
	for (i=1;i<=n;i++)
		muestra_alumno(lis[i]);		
}
		
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
			
