#include <stdio.h>
void ingresarVehiculo(char *tv, short *he, short *me, short *hs, short *ms);
char validarVehiculo();
short hsEstacionado(short he, short me, short hs, short ms);

int main() {
	
	char Tveh;
	short HorE, MinE, HorS, MinS, tiempo;
	float Tarifa, Monto;
	
	//Infresar la Tarifa
	printf("Ingrese la tarifa basica:\n");
	scanf("%f", &Tarifa);
	//Ingresar datos del vehiculo
	ingresarVehiculo(&Tveh, &HorE, &MinE, &HorS, &MinS);
	//EstadiahsEstacionado
	tiempo = hsEstacionado(HorE, MinE, HorS, MinS);
	return 0;
}

void ingresarVehiculo(char *tv, short *he, short *me, short *hs, short *ms){
	
	*tv = validarVehiculo();
	printf("Ingrese la hora de ingreso:\n");
	scanf("%hd", he);
	printf("Ingrese el minuto de ingreso:\n");
	scanf("%hd", me);
	printf("Ingrese la hora de salida:\n");
	scanf("%hd", hs);
	printf("Ingrese el minuto de salida:\n");
	scanf("%hd", ms);
}

char validarVehiculo(){
	char tipoV;
	do{
		fflush(stdin);
		printf("Ingrese el tipo de vehiculo:\n"
			   "Moto: Marque M \n"
			   "Auto: Marque A \n"
			   "Camioneta: Marque C \n");
		scanf("%c", &tipoV);
	}while(tipoV!='M' && tipoV!='A' && tipoV!='C');
	return tipoV;
}

short hsEstacionado(short he, short me, short hs, short ms){
	short Estadia;
	Estadia = hs - he;
	if (me - ms > 0)
		Estadia++;
	return Estadia;
}
