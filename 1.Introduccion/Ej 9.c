#include <stdio.h>

int main() {
	
	int hi, hs, minIng, minSal, tarifaBasica, Veh, hsEstacionado;
	printf("Ingrese la hora de ingreso:\n");
	scanf("%d", &hi);
	printf("Ingrese el minuto de ingreso:\n");
	scanf("%d", &minIng);
	printf("Ingrese la hora de salida:\n");
	scanf("%d", &hs);
	printf("Ingrese el minuto de salida:\n");
	scanf("%d", &minSal);
	
	printf("Ingrese la tarifa basica en pesos.\n");
	scanf("%d", &tarifaBasica);
	
	printf("Ingrese el tipo de vehiculo:\n"
		   "Moto: Marque 1 \n"
		   "Auto: Marque 2 \n"
		   "Camioneta: Marque 3 \n");
	scanf("%d", &Veh);
	
	hsEstacionado = hs - hi;
	if (minSal - minIng > 0)
		hsEstacionado++;
	
	switch(Veh)
	{
		case 1: printf("Tarifa: %d", tarifaBasica*hsEstacionado); break;
		case 2: printf("Tarifa: %d", tarifaBasica*2*hsEstacionado); break;
		case 3: printf("Tarifa: %d", tarifaBasica*3*hsEstacionado); break;
	}
	
	return 0;
}

