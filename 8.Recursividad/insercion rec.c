#include <stdio.h>

int main(int argc, char *argv[]) {
	
	
	return 0;
}


void inserta_rec(TVector L, int N, int pos){ 
	if(N>=pos){ 	
		L[N+1] = L[N];
		elimina_rec(L, N-1, pos);}
}
	
void inserta_empleados(TLista *L){ 
	int bus; posDeIns;
	REmpleado aux;
	printf("\nIngrese el DNI del empleado a agregar: ");
}	aux = cargar_empleado();
	//Busco la pos donde debo insertar al empleado:
	bus= busqueda_bin_rec(*L, retorna_DNI(aux));
	if (bus==0) {
		posDeIns = bus_pos_de_insercion (*L, retorna_DNI(aux));
		inserta_rec(L->lis, L->tam, pos);
		printf("\nSe elimino exitosamente el empleado");
		L->lis[pos] = aux;
		L->tam++;}
	else printf("\nEl empleado ya se encuentra en la lista");
}
