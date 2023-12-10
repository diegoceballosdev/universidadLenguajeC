#include "TAD_ListaEmpleados.h"

TLista inicializa_lista(){
	TLista aux;
	aux.tam=0;
	return aux;
}
	
int retorna_tam(TLista A){
	return A.tam;
}
	
void carga_rec(TVector L, int tam){ 
	if (tam>0){ 
		carga_rec(L, tam-1);
		printf("\nIngrese Empleado[%d]= ", tam);
		L[tam]=cargar_empleado(); 
	}
}
	
TLista carga_empleados(){ 
	TLista L;
	printf("\nIngrese la cantidad de empleados: ");
	scanf("%d", &L.tam);
	carga_rec(L.lis, L.tam);
	return L;
}
	
int bb_recursiva(TVector A, int ini, int fin, long DNI){
	int med;
	med=(ini+fin)/2;
	if(compara_DNI(A[med],DNI)!=0 && ini<=fin){	
		if(compara_DNI(A[med],DNI)==1) fin=med-1;
		else ini=med+1;
		return bb_recursiva(A, ini, fin, DNI);
	}
	if(ini>fin) return -1;
	else return med;
}

int busqueda_bin_rec(TLista A, long DNI){
	int ini, fin, rdo;
	ini= 1;
	fin= A.tam;
	rdo=bb_recursiva(A.lis, ini, fin, DNI);
	return rdo;	
}

void agrega_empleados(TLista *L){ 
	int pos;
	REmpleado nvo;
	nvo= cargar_empleado();
	pos= busqueda_bin_rec(*L, retorna_DNI(nvo));
	if (pos==-1){
		L->tam++;
		L->lis[L->tam]= nvo;
		printf("\n\n Se agrego exitosamente el nuevo empleado \n");
	}
	else printf("\n\n El empleado ya esta cargado\n");
}

void elimina_rec(TVector L, int N, int pos){ 
	if(pos<N){ 	
		L[pos] = L[pos+1];
		elimina_rec(L, N, pos+1);}
}
	
void elimina_empleados(TLista *L){ 
	int pos;
	long DNI;
	printf("\nIngrese el DNI del empleado a eliminar: ");
	scanf("%ld", &DNI);
	pos= busqueda_bin_rec(*L, DNI);
	if (pos!=-1) {
		elimina_rec(L->lis, L->tam, pos);
		printf("\nSe elimino exitosamente el empleado");
		L->tam--;}
	else printf("\nEl empleado no se encuentra");
}
	
void modifica_empleados(TLista *L){ 
	int pos;
	long DNI;
	printf("\nIngrese el DNI del empleado a modificar: ");
	scanf("%ld", &DNI);
	pos= busqueda_bin_rec(*L, DNI);
	if (pos!=-1){
		modificar_empleado(&L->lis[pos]);
		printf("\nSe modifico exitosamente el empleado");
	}	
	else printf("\nEl empleado no se encuentra");
}
	
void mostrar_rec(TVector L, int N){ 
	if (N>0) {
		mostrar_rec(L, N-1);
		mostrar_empleado(L[N]); 
	}
}
void mostrar_empleados(TLista L){
	mostrar_rec(L.lis, L.tam);
}
	
void mostrar_ET_rec(TVector L, int N, int Xesp, int Xtur){
	if(N>0) { 
		mostrar_ET_rec(L, N-1, Xesp, Xtur);
		if(compara_emp_ET(L[N], Xesp, Xtur)==1) 
			mostrar_empleado(L[N]); 
	}
}

void mostrar_esp_turno(TLista L){
	int Xesp, Xtur;
	printf("\nEspecialidad solicitada: 1[Administrativo],2[Tecnico],3[Limpieza],4[Transporte]");
	printf("\nIngrese su eleccion: ");
	scanf("%d", & Xesp);
	printf("\nTurno solicitado: 1[Mañana], 2[Tarde], 3[Noche]");
	printf("\nIngrese su eleccion: ");
	scanf("%d", & Xtur);
	mostrar_ET_rec(L.lis, L.tam, Xesp, Xtur);
}

void genera_rec(TVector A, int N, TVector D, int *M, int Xesp, int Xest){
	if(N>0) {
		if(compara_emp_ET(A[N], Xesp, 1)==1) { 	
			(*M)++;
			D[*M]= A[N];
			genera_rec(A, N-1, D, M, Xesp, 1); }
		else genera_rec(A, N-1, D, M, Xesp, 1);
	} 
}
	
void genera_esp_libre(TLista A, TLista *D){
	int Xesp;
	D->tam = 0;
	printf("\nEspecialidad solicitada:1[Administrativo],2[Tecnico],3[Limpieza],4[Transporte]");
	printf("\nIngrese su eleccion: ");
	scanf("%d", & Xesp);
	genera_rec(A.lis, A.tam, D->lis, &D->tam, Xesp, 1);
}
	
void mezcla(TVector A,int ini, int m, int fin){
	int i,j,k,t;
	TVector aux; 
	k= 0;
	i= ini;
	j= m+1;
	while (i<=m && j<=fin){
		k++;
		if (compara_RDNI(A[j], A[i])==1){
				aux[k]=A[i];
				i++;
		}
		else{
			aux[k]=A[j];
			j++;
		}
	}
	for(t=i;t<=m;t++){
		k++;
		aux[k]=A[t];
	}
	for(t=j;t<=fin;t++){
		k++;
		aux[k]=A[t];
	}
	for(t=1;t<=k;t++){
		A[ini+t-1]=aux[t];
	}
}
		
void m_sort(TVector A, int ini, int fin) {
	int med;
	med=(ini+fin)/2;
	if (ini<fin){	
		m_sort(A,ini,med);
		m_sort(A,med+1,fin);
		mezcla(A,ini,med,fin); 
	}
}

void ordenar_dni(TLista *D){
	int ini, fin;
	ini = 1;
	fin = D->tam;
	m_sort(D->lis, ini, fin); 
}

