#include <stdio.h>

int main() {
	
	short hi, hs, minIng, minSal, hsEstacionado, Veh;
	float tarifaBasica;
	
	printf("Ingrese la tarifa basica en pesos.\n");
	scanf("%f", &tarifaBasica);
	
	printf("Ingrese el tipo de vehiculo:\n"
		   "Moto: Marque 1 \n"
		   "Auto: Marque 2 \n"
		   "Camioneta: Marque 3 \n");
	scanf("%hd", &Veh);
	
	printf("Ingrese la hora de ingreso:\n");
	scanf("%hd", &hi);
	printf("Ingrese el minuto de ingreso:\n");
	scanf("%hd", &minIng);
	printf("Ingrese la hora de salida:\n");
	scanf("%hd", &hs);
	printf("Ingrese el minuto de salida:\n");
	scanf("%hd", &minSal);

	hsEstacionado = hs - hi;
	if (minSal - minIng > 0)
		hsEstacionado++;
	
	switch(Veh)
	{
	case 1: printf("Tarifa: %f", tarifaBasica*hsEstacionado); break;
	case 2: printf("Tarifa: %f", tarifaBasica*2*hsEstacionado); break;
	case 3: printf("Tarifa: %f", tarifaBasica*3*hsEstacionado); break;
	}
	
	return 0;
}
