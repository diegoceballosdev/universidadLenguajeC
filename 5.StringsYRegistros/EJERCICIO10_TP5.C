/*EJERCICIO 10 : Se tiene los datos de dos círculos. Estos datos son: el nombre, el punto central y el radio.
Se solicita ingresar N puntos del plano e indicar, para cada punto, el círculo al cual el punto es interior, o si es exterior a ambos círculos.
Nota: utilizar TD registro para representar cada círculo y cada punto*/

#include <stdio.h>
#include <math.h>
#define MAXIMO 30

typedef char Tcad [MAXIMO] ; 

typedef struct{
	float x; 
	float y; 
} Tpunto ; 

typedef struct {
	Tcad nombre ; 
	Tpunto med ; 
	float radio ; 
}Tcirculos ; 

void leeCad (Tcad, int ) ;
Tpunto carg_pts (); 
Tcirculos carga_c (); 
void punto_plano (Tpunto[], int *) ; 
void  indc (Tpunto [], Tcirculos, Tcirculos, int ) ; 

int main(int argc, char *argv[]) {
	int N ; 
	
	Tcirculos CI1 ;
	Tcirculos CI2 ;
	Tpunto X [MAXIMO] ;
	printf ("\nIngrese los datos del primer circulo"); 
	CI1=carga_c() ;
	printf ("\nIngrese los datos del segundo circulo");
	CI2=carga_c() ;
	punto_plano (X,&N);
	indc (X,CI1,CI2,N) ; 
	return 0 ; 
}

void leeCad (Tcad x , int  tam){
	
	int i , j ;
	i = 0 ; 
	while ( i<tam-1 && (j=getchar())!=EOF && j!= '\n'){
		x [i] = j ;
		i++;
	}
	x [i]='\0' ; 
	if (j!=EOF && j != '\n')
		while ((j=getchar ())!=EOF && j != '\n' ) ; 
}
	
Tpunto carg_pts (){
	Tpunto aux ; 
	printf ("\nIngrese X: ") ; 
	scanf ("%f",&aux.x); 
	printf ("\nIngrese Y: ") ; 
	scanf ("%f",&aux.y);
	return aux ; 
}
 
Tcirculos carga_c () {
	Tcirculos aux ; 
	fflush (stdin) ; 
	printf ("\nIngrese el nombre del circulo: ") ; 
	leeCad ( aux.nombre, MAXIMO) ; 
	fflush (stdin);
	aux.med = carg_pts () ; 
	printf ("\nIngrese el radio: ") ; 
	scanf ("%f",&aux.radio) ; 
	return aux ; 
}	
 
void punto_plano (Tpunto v [], int *nj){
	int i ; 
	printf ("\nIngrese la cantidad de puntos a ingresar " ) ; 
	scanf ("%d", nj ) ;
	for (i=1 ; i <= *nj ; i++){
		v [i] =carg_pts (); 
	}
}

void indc (Tpunto V [], Tcirculos A , Tcirculos B , int M ){
	int i; 
	for (i=1 ; i<=M ; i++ ){
		if (sqrt(pow(V[i].x- A.med.x, 2) + pow(V[i].y- A.med.y, 2))< A.radio)
			printf ("\nEl punto %f , % f es interior a %f ", V[i].x , V[i].y , A.radio ) ;
		else 
			if (sqrt(pow(V[i].x- A.med.x, 2) + pow(V[i].y- A.med.y, 2))>A.radio)
				printf ("\nEl punto %f , % f es exterior a %f ", V[i].x , V[i].y , A.radio ) ;
		if (sqrt(pow(V[i].x- B.med.x, 2) + pow(V[i].y- B.med.y, 2))< B.radio)
			printf ("\nEl punto %f , % f es interior a %f ", V[i].x , V[i].y , B.radio ) ;
		else 
			if (sqrt(pow(V[i].x- B.med.x, 2) + pow(V[i].y- B.med.y, 2))> B.radio)
				printf ("\nEl punto %f , % f es exterior  a %f ", V[i].x , V[i].y , B.radio) ;
	 }
 }
