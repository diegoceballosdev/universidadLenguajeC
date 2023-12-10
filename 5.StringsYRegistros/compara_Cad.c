/* Ingresar los Apellidos y Nombres de 2 personas. Luego mostrarlos ordenados 
alfabeticamente*/

#include <stdio.h>
#include <string.h>

#define MAXCAR 45

typedef char Tcad[MAXCAR];

/*** prototipos ***/
void leeCad(Tcad, int); /* Lee cadena*/

int main(int argc, char *argv[]) {
	Tcad nombre1,nombre2;
	
	printf("\nIngrese el apellido y nombre de la persona 1: ");
	leeCad(nombre1,MAXCAR);
	printf("\nIngrese el apellido y nombre de la persona 2: ");
	leeCad(nombre2,MAXCAR);
	if(strcmp(nombre1,nombre2)==-1)
		printf("\n%s\n%s",nombre1,nombre2);
	else{
		if(strcmp(nombre1,nombre2)==1)
		printf("\n%s\n%s",nombre2,nombre1);
		else
			printf("\nLos apellidos y nombres ingresados son iguales");
	}	
	return 0;
}
/*** Definicion de Modulos**/
void leeCad(Tcad cadena, int tam ){
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
	
