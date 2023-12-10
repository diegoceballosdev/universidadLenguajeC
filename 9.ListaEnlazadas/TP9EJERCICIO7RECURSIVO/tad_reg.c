#include "tad_reg.h" 
/**MODULO PRIVADO**/ 
/**MODULO PUBLICO**/ 
Talumno carga_alumno(long doc){
	Talumno alu;
	long c;
	alu.dni= doc;
	printf("\nIngrese el Apellido y Nombre: ");
	fflush(stdin);
	ing_cad (alu.ApeNom) ; 
	printf("\nIngrese 1: Regular, 2: Libre");
	printf("\nIngrese condicion de alumno:  ");
	scanf("%ld", &c);
	alu.cond= c;
	return alu;
}
	
void muestra_alumno(Talumno alu){
	tcad pal; 
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
