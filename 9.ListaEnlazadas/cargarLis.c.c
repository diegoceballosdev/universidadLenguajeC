#include <stdio.h>

int main(int argc, char *argv[]) {
	
	return 0;
}

void cargarLista (T_Ptro *lis){
// *lis es lo mismo que *cab
	T_ptro nvo;
	nvo = crearNodo();
	if (*lis == NULL)
		*lis = nvo;
	else{
		nvo->sig = *lis;
		*lis = nvo;
	}
}


void cargarLista (T_Ptro *lis){
	T_ptro nvo;
	int i, N;
	printf("\n Ingrese cant. de elem.:");
	scanf("&d", &N);
	for(i=1; i<=N; i++){
		nvo = crearNodo();
		nvo->sig = *lis;
		*lis = nvo
	}
}

	
