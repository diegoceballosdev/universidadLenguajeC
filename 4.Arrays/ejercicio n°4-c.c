#include <stdio.h>
#include <math.h>
#define F 51
typedef int vector[F];
void ingresar_vector(vector primero,int *TAM);
void mostrar_vector(vector primero,int t);
float calcular_promedio(vector LISTA,int TN);
void modificar_vector(vector LISTA,int TM,float p,short *band);
int main(void) {
	vector A;
	int N;
	short b=0;
	ingresar_vector(A,&N);
	float promedio;
	if (N==0)
		printf("\n no hay vector");
	else{
		printf("\n el vector ingresado es :");
		mostrar_vector(A,N);
		promedio=calcular_promedio(A,N);
		printf("\n el promedio es %f",promedio);
		modificar_vector(A,N,promedio,&b);
		if(b==0)
			printf("\n no hubo modificación en el vector");
		else 
			printf("\n hubo modificación en el vector ");
		mostrar_vector(A,N);
	}
	return 0;
}
/* MÓDULOS */
short es_entero(float num){
	short band=0;
	if (num<0)
		num=num*(-1);
	int valor=fabs(num);
	if (num==valor)
		band=1;
	return band;
}
void ingresar_vector(vector primero,int *TAM){
	float aux;
	short band=1;
	int T=0,j;
	do{
		printf("\n ingresar elemento ");
		scanf("%f",&aux);
		if(es_entero(aux)){
			if(T==0){
				T=1;
				primero[1]=aux;
			}
		    else {
				j=T;
				while(0<j){
					primero[j+1]=primero[j];
					j=j-1;
				}
				primero[j+1]=aux;
				T=T+1;
			}
		}
		else
			band=0;   
	} while(band==1);
	*TAM=T;
}
void mostrar_vector(vector primero,int t){
	int i;
	for(i=1;i<=t;i++)
		printf("\n el elemento:%d",primero[i]);
}
float calcular_promedio(vector LISTA,int TN){
	float promi=0;
	int i;
	for(i=1;i<=TN;i++)
		promi=promi+LISTA[i];
	promi/=TN;
	return promi;	
}
void modificar_vector(vector LISTA,int TM,float p,short *band){
	int i;
	for(i=1;i<=TM;i++)
		if (p<LISTA[i]){
			*band=1;
			LISTA[i]=LISTA[i]-p;
		}
}
