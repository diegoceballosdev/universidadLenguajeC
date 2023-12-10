#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCAD 20

typedef char Tcad [MAXCAD];

void leeCad (Tcad , int);
void recorrerCad (Tcad);

int main(int argc, char *argv[]) {
	
	Tcad name, surname;	
	int resComp;
	
	/*	INGRESO DE CAENAS*/
	printf("ingrese nombre: \n");
	leeCad(name, MAXCAD);
	fflush(stdin);
	printf("ingrese apellido: \n");
	leeCad(surname, MAXCAD);
	fflush(stdin);
	
	/*	MOSTRAR CADENA*/
	printf ("usted se llama %s %s \n", name, surname);
	
	/*	MODIFICO LA CADENA*/
	printf("ingrese NUEVO nombre: \n");
	fflush(stdin);
	leeCad(name, MAXCAD);
	printf ("usted se llama %s %s \n", name, surname);
	
	/*	RECORRER CADENA*/ 
	/*Mostrar cada letra de la cadena*/
	recorrerCad (surname);
	
	/*	COMPARAR CADENAS*/
	resComp = strcmp (name, surname);
	if (resComp == 1) printf("name es mayor");
	else{
		if (resComp == 0) printf("iguales");
		else printf("name es menor");
	}
	return 0;
	
}


void leeCad (Tcad cadena, int tam){
	int j,m;
	j=0;
	while (j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		cadena[j]=m;
		j++;
	}
	cadena[j]='\0';
	if (m != EOF && m!= '\n' )
		while ((m=getchar())!=EOF && m!='\n');
}
void recorrerCad (Tcad cadena){
	int tam, i;
	tam = strlen (cadena);
	for(i=0; i<tam; i++){
		printf("La %d° letra es: %c \n", i+1, cadena[i]);
	}
}
	
