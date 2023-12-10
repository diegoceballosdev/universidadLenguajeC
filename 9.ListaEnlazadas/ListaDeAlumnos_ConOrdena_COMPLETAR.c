/*Ejercicio: Diseñar un programa que permita a través de un menú de opciones
administrar una lista de N alumnos, los cuales se agregan al principio de la lista. Por cada alumno 
se registra: DNI, Apellido y Nombre del alumno, Condición 
(1: Regular / 2: Libre). El programa debe permitir: Mostrar la lista ingresada; dado un DNI mostrar los datos 
del alumno; dado un DNI eliminarlo de la lista;  y ordenar la lista (utilizando otra lista). 

VARIANTE: crear los TADs que considere necesarios.*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/** Cadena*/
#define TMAX 50
typedef char Tcad[TMAX];
void leecad(Tcad , int );

/** Alumno **/
typedef struct{
	Tcad ApeNom;
	long dni;
	int cond;
}Talumno;

Talumno carga_alumno(long);
void muestra_alumno(Talumno);
long retorna_dni(Talumno);

/** Lista Enlazada */
typedef struct nodo{
	Talumno dato;
	struct nodo *sig;
}Tnodo;

typedef Tnodo* Tlista;

//int valida(Tlista, long);
Tlista crea_nodo(); /* crea un nodo de LE*/
Tlista crea_lista();/* crea LE con n nodos agregados al inicio -con validacion dni*/
void agrega_cab(Tlista *, Tlista);/* Agrega nodo al inicio de LE*/
void agrega_nodo(Tlista *, Tlista);/* Agrega nodo en la LE segun dni*/
void muestra_lista(Tlista); /* Muestra LE*/
void MuestraAlumnoDNI(Tlista, long);/* ubica en la LE el dni del alum del cual mostrara datos*/
void Mostrar_Alumno(Tlista);/* ingrese dni del alumno a mostrar datos*/
void Eliminar_Alumno(Tlista*);/* ingrese dni del alumno a elimina*/
void EliminaAlumno(Tlista *, long);/* ubica en la LE el dni del alumno a eliminar*/
void ordena_otralista(Tlista *,Tlista *);/* utiliza otra lista para Ordenar nodos de LE*/ 
void ordena_lista(Tlista *);/* ordena LE*/

/* Otros */
int menu(void);

/** MAIN */
int main(int argc, char *argv[]) {
	Tlista LISTA=NULL;
	int op;
	
	LISTA=crea_lista();
	
	do{
		op = menu();
		switch(op)
		{
		case 0: printf("\nFin del programa"); 
		break;
		case 1: muestra_lista(LISTA);
		break;
		case 2:	Mostrar_Alumno(LISTA);
		break;
		case 3:	Eliminar_Alumno(&LISTA);
		break;
		case 4: /** COMPLETAR*/
		break;
		default: printf("\nOpcion no valida");
		}		
	} while(op!=0);	
	return 0;
}

/** IMPLEMENTACION*/

/** Registro alumno*/
Talumno carga_alumno(long doc){
	Talumno alu;
	long c;
	
	alu.dni= doc;
	printf("\nIngrese el Apellido y Nombre: ");
	fflush(stdin);
	leecad(alu.ApeNom, TMAX);
	printf("\nIngrese 1: Regular, 2: Libre");
	printf("\nIngrese condicion de alumno:  ");
	scanf("%ld", &c);
	alu.cond= c;
	return alu;
}
	
void muestra_alumno(Talumno alu){
	Tcad pal; 
	int c;
	c=alu.cond;
	switch(c){
		case 1: strcpy(pal, "Regular"); 
		break;
		case 2: strcpy(pal, "Libre"); 
		break;
	}
	printf("\n ");
	printf("\nDNI: %ld, Nombre: %s y Condicion: %s",alu.dni,alu.ApeNom,pal);	
}

long retorna_dni(Talumno alu){
	return alu.dni;	
}
	
/** Lista Enlazada - Alumnos*/

Tlista crea_nodo(long doc){
	Tlista nvo;

	nvo=(Tlista)malloc(sizeof(Tnodo));
	nvo->dato =carga_alumno(doc);
	nvo->sig=NULL;
	return nvo;
}

void agrega_cab(Tlista *cab, Tlista nodo){
	nodo->sig= *cab;
	*cab=nodo;
}

void agrega_nodo(Tlista *cab, Tlista nodo){
	Tlista ant=NULL,aux=NULL;
	if (*cab==NULL) /* la lista esta vacia*/
		*cab=nodo;
	else{
		/*la lista NO está vacia.Debo "ubicar" punteros ANT y DES donde voy a agregar el nodo*/
		aux=*cab;
		ant=NULL;						
		while (aux!=NULL && retorna_dni(nodo->dato)>retorna_dni(aux->dato)){
			//se podría agregar un módulo que compare el campo dni de 2 nodos??
			ant=aux;
			aux = aux->sig;
		}
		if (ant==NULL) /* debo agregar al principio de la lista */
			agrega_cab(cab,nodo);
		else {	/* NO debo agregar al ppio de la lista*/
			ant->sig=nodo;
			nodo->sig=aux;
		}
	}
}

int valida(Tlista cab, long doc){ 
	/** verifica si existe o no en la lista el nro de doc ingresado*/
	if (cab!=NULL)	{	
		while (cab->sig!=NULL && retorna_dni(cab->dato)!=doc)	
			cab=cab->sig;
		if (retorna_dni(cab->dato)==doc) 
			return 1;
		else 
			return 0;
	}
	else
		return 0;
}

Tlista crea_lista(){
	Tlista cab, otro;
	int i, n, rta;
	long doc;
								
	cab=NULL;								
	printf("\n cantidad de elementos a ingresar: ");
	scanf("%d",&n);
								
	for(i=1;i<=n;i++){
		do{
			/** podria modularizarse la validacion do/while*/
			printf("\nIngrese Numero de Documento: ");
			scanf("%ld", &doc);
			rta= valida(cab, doc);
		}while (rta!=0);
		/***/
		otro=crea_nodo(doc);
		agrega_cab(&cab,otro);
	// agrega_nodo(&cab,otro); /* para crear lista de n nodos ordenados segun su dni*/
	}
	return cab;
}

void ordena_otralista(Tlista *cab,Tlista *cab2){
	Tlista aux;	
	aux = *cab;
	
	while (aux != NULL &&){
		agrega_nodo(cab2, aux); //Lo agrega ordenadamente
		aux = aux->sig;
	}
	*cab = *cab2;
}
	
void ordena_lista(Tlista *cab){
	Tlista cab2;
	if(*cab !=NULL){
		cab2 = NULL;
		ordena_otralista(cab, &cab2)
	}
	else 
	   printf("\n lista vacia");
}
	
void muestra_lista(Tlista cab){
	if (cab!=NULL)	
		while (cab != NULL)	{
			muestra_alumno(cab->dato);
			cab=cab->sig;
		}
		else
			printf("\n lista vacia");
}


void MuestraAlumnoDNI(Tlista cab, long doc){ 
	if (cab!=NULL)	{	
		while (cab != NULL && retorna_dni(cab->dato)!=doc)	
			// se podría agregar un módulo que compare el campo dni de un nodo con un lonng?
			cab=cab->sig;
		if (cab!=NULL) 
			muestra_alumno(cab->dato);
		else 
			printf("\nEl DNI no existe");
	}
	else	 
		printf("\nLista vacia");
}
	
void Mostrar_Alumno(Tlista cab){
	long doc;

	printf("\nIngrese DNI: ");
	scanf("%ld", &doc);
	MuestraAlumnoDNI(cab, doc);
}
	
void EliminaAlumno(Tlista *cab, long doc){
	Tlista aux,ant;
	
	if (*cab!=NULL)
	{ ant= NULL; aux= *cab;
		while(aux!=NULL && retorna_dni(aux->dato)!=doc)
		{ ant= aux;
		  aux= aux->sig; 
		}
		if(ant==NULL) { 
		  *cab= aux->sig;
		   aux= NULL; 
		}
		else { 
			if(aux!=NULL)
			{ ant->sig= aux->sig;
			 aux->sig= NULL; 
		    }
		   else printf("\n No esta el valor"); }
		   free(aux); 
	}
	else printf("\n Lista Vacia");
}
void Eliminar_Alumno(Tlista *cab){
	long doc;

	printf("\nIngrese DNI: ");
	scanf("%ld", &doc);
	EliminaAlumno(cab, doc);
}

int menu(){
	int op;
	printf("\n*************************************\n");
	printf("\nMenu de opciones");
	printf("\n ");
	printf("\n0: Salir del Programa");
	printf("\n1: Mostrar Lista");
	printf("\n2: Mostrar los datos de un alumno");
	printf("\n3: Eliminar un alumno");
	printf("\n4: Ordenar lista de alumnos");	
	printf("\n ");
	printf("\nIngrese opcion deseada: ");
	scanf("%d", &op);
	return op;

}
void leecad(Tcad A, int tmax)
{
	int j=0; char c;
	c=getchar();
		
	while(j<tmax && c!=EOF && c!='\n'){
		A[j]=c;
		j++;
		c=getchar();}
	A[j]='\0';
	while(c!=EOF && c!='\n')
		c=getchar();
	}
