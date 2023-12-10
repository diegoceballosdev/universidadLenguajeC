#include <stdio.h>

int main(int argc, char *argv[]) {
	
	return 0;
}

void quickSort(Tvec V, int ini, int fin){
	//Declaracion
	Treg pivot;
	int izq, der, m;
	
	//Caso base
	if (ini < fin){
		//Inicializa
		pivot = V[ini];
		izq = ini;
		der = fin;
		
		//Mover elementos del vector a los lados del pivot
		while (izq < der){
			
			while(der>izq && returnDNI(V[der]) > returnDNI(pivot))
				der--;
			if(der>izq){
				V[izq] = V[der];
				izq++;
			}
			
			while(izq<der && returnDNI(V[izq]) < returnDNI(pivot))
			   izq++;
			if(izq<der){
				   V[der] = V[izq];
				   der--;
			}
		}
		
		V[der] = pivot; //ubico el pivot
		m = der; //establecer medio para separar la lista y rellamar
		
		//Rellamadas
		quickSort(V, ini, m-1);
		quickSort(V, m+1, fin);
	}
}

void ordenarLista(Tlista *L){
	int ini, fin;
	ini = 1;
	fin = L.tam;
	quickSort(L.lista, ini, fin);
}
	
