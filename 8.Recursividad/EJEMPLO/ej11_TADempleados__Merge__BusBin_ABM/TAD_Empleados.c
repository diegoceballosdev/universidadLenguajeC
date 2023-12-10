#include "TAD_Empleados.h"
#include <stdlib.h>


REmpleado cargar_empleado(){
	/* 
	Estado (Libre, Ocupado).*/
	REmpleado nvo;
	fflush(stdin);
	printf("\nIngrese el Nombre del empleado: ");
	leeCad(nvo.nom, 20);
	fflush(stdin);
	printf("\nIngrese el Apellido del Empleado: ");
	leeCad(nvo.ape, 20);
	fflush(stdin);
	printf("\nIngrese el DNI del empleado: ");
	scanf("%ld", & nvo.dni);
	printf("\nTipo de Especialidad; 1: Administrativo, 2: Tecnico, 3: Limpieza, 4: Transporte");
	printf("\nIngrese su eleccion: ");
	scanf("%d", & nvo.esp);
	printf("\nTarea actual; 1: Con tarea, 2: Sin tarea");
	printf("\nIngrese su eleccion: ");
	scanf("%d", & nvo.tarea);
	printf("\nHorario de trabajo; 1: Mañana, 2: Tarde, 3: Noche");
	printf("\nIngrese su eleccion: ");
	scanf("%d", & nvo.turno);
	printf("\nEstado; 1: Libre, 2: Ocupado");
	printf("\nIngrese su eleccion: ");
	scanf("%d", & nvo.est);
	
	return nvo;
}
	
void mostrar_empleado(REmpleado emp){
	printf("\nNombre y Apellido del empleado: %s %s su DNI: %ld", emp.nom, emp.ape, emp.dni);
	switch (emp.esp){
	case 1: printf("\nEspecialidad: Admistrativo");
			break;
	case 2: printf("\nEspecialidad: Tecnico");
			break;
	case 3: printf("\nEspecialidad: Limpieza");
			break;
	case 4: printf("\nEspecialidad: Transporte");
			break;
	}
	switch (emp.tarea){
	case 1: printf("\nTarea actual: Con Tarea");
			break;
	case 2: printf("\nTarea actual: Sin Tarea");
			break;
	}
	switch (emp.turno){
	case 1: printf("\nHorario de trabajo: Mañana");
			break;
	case 2: printf("\nHorario de trabajo: Tarde");
			break;
	case 3: printf("\nHorario de trabajo: Noche");
			break;
	}
	switch (emp.est){
	case 1: printf("\nEstado actual: Libre");
			break;
	case 2: printf("\nEstado actual: Ocupado");
			break;
	}
}

void modificar_empleado(REmpleado * emp){
	REmpleado nemp;
	nemp= *emp;
	printf("\n---- Datos actuales del empleado ----");
	mostrar_empleado(nemp);
	printf("\n---- Modificar todos los Datos actuales del empleado ----");
	nemp= cargar_empleado();
	*emp= nemp;
}

long retorna_DNI(REmpleado emp){
	return emp.dni;
}

int compara_DNI(REmpleado emp, long DNI){
	if(emp.dni>DNI) return 1;
	else {
		if(emp.dni<DNI) return -1;
		else return 0;
	}	
}

int compara_emp_ET(REmpleado emp, int Xesp, int Xtur){
	if(emp.esp==Xesp && emp.turno==Xtur) return 1;
	else return 0;
}

int compara_emp_esp(REmpleado emp1, REmpleado emp2){
	if(emp1.esp>emp2.esp) return 1;
	else if(emp1.esp<emp2.esp) return -11;
		 else return 0;
}

int compara_RDNI(REmpleado emp, REmpleado emp2){
	if(emp.dni>emp2.dni) return 1;
	else if(emp.dni<emp2.dni) return -1;
		 else return 0;
}
