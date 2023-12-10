#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long ingresarFecha (void);
long formarFecha (int, int, int);
long generarFecha (long);

int main() {
	long F1, F2;
	
	F1 = ingresarFecha();
	printf("fecha ingresada: %ld", F1);
	F2 = generarFecha (F1);
	printf("fecha: %ld", F2);
	return 0;
}

long ingresarFecha (void){
	long Fecha1;
	int dd, mm, aa;
	printf("Ingrese el dia: \n");
	scanf("%d",&dd);
	printf("Ingrese el mes: \n");
	scanf("%d",&mm);
	printf("Ingrese el año: \n");
	scanf("%d",&aa);
	Fecha1 = formarFecha (dd,mm,aa);
	return Fecha1;
}
long formarFecha (int day, int month, int year){
	long ddmmaa;
	ddmmaa = day*10000+month*100+year;
	return ddmmaa;	
}



long generarFecha (long fechaInicial){
	long fechaFinal, fechaLimite;
	fechaLimite = 301222;
	srand(time(NULL));
	
	return fechaFinal;
}
