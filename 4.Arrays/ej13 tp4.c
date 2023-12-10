/*Ej13 TPN4: Se requiere cargar la informacion asociada a M miembros de una institucion deportiva, la informacion
de cada miembro es: DNI, celular, estado (C: casado, S: soltero, V: viudo, W: separado) y edad. Se solicita un
programa modular que permita cargar la lista de miembros de la institucion y que la misma se ordene por el campo
DNI, a medida que se ingresan los miembros. Luego presente un menu de opciones que permita las siguientes 
operaciones:
a. Dado un DNI determinar si este se encuentra en la lista de miembros cargados
b. Eliminar un miembro de la lista ingresando por teclado su DNI
c. Agregar un nuevo miembro a la lista
d. Dado un estado ingresado por teclado, mostrar la informacion de los registros que sean iguales al estado
solicitado
e. Mostrar la lista de miembros.*/

#include <stdio.h>
#define Tam 50

typedef long TLlista [Tam]; /*para vector DNI y celular*/
typedef char TClista [Tam]; /*para vector estado*/
typedef int TIlista [Tam]; /*para vector edad*/

/*PROTOTIPOS*/
void cargar_lista(TLlista, TLlista, TClista, TIlista, int*);
void mostrar_lista(TLlista, TLlista, TClista, TIlista, int);
int busqueda_dni(TLlista, int, long);
void eliminar(TLlista, TLlista, TClista, TIlista, int*, int);
void agregar(TLlista, TLlista, TClista, TIlista, int*, int, long, long, char, int);
void mostrar_informacion(TLlista,TLlista,TClista,TIlista,int,char);
int menu();

/*MAIN*/
int main(void) {
	int M, op, resp, edad, j, b;
	long dni, celu;
	char estado;
	TLlista vecD, vecC;
	TClista vecES;
	TIlista vecED;
	cargar_lista(vecD,vecC,vecES,vecED,&M);
	do{
		op=menu();
		switch(op){
		case 0: 
			printf("\n FIN DEL PROGRAMA \n");
		break;
		case 1: /*inciso a: ingresa dni, lo busca y determina si esta o no en la lista*/
			printf("\n Ingrese DNI a buscar: ");
			scanf("%ld", &dni);
			resp=busqueda_dni(vecD,M,dni);
			if(resp>0)
				printf("\n El DNI ingresado si esta en la lista de miembros");
			else
				printf("\n El DNI ingresado no esta en la lista de miembros");
			break;
		case 2: /*inciso b: ingresa dni a eliminar, lo busca y elimina todo el registro de ese dni*/
			printf("\n Ingrese DNI a eliminar: ");
			scanf("%ld", &dni);
			resp=busqueda_dni(vecD,M,dni);
			eliminar(vecD,vecC,vecES,vecED,&M,resp);
			mostrar_lista(vecD,vecC,vecES,vecED,M);
			break;
		case 3: /*inciso c: agrega un nuevo miembro a la lista por medio del dni*/
			printf("\n Ingrese DNI a agregar: ");
			scanf("%ld", &dni);
			printf("\n Nro de celular: ");
			scanf("%ld", &celu);
			fflush(stdin);
			printf("\n Estado Civil (C-casado, S-soltero, V-viudo, W-separado): ");
			scanf("%c", &estado);
			printf("\n Edad: ");
			scanf("%d", &edad);
			j=1; b=0;
			while(j<=M && b==0){
				if(dni<vecD[j]){
					agregar(vecD,vecC,vecES,vecED,&M,j,dni,celu,estado,edad);
					b=1;
				}
				j=j+1;
			}
			mostrar_lista(vecD,vecC,vecES,vecED,M);
			break;
		case 4: /*inciso d:ingresa un est civil y muestra la info del registro igual al estado ingresado*/
			fflush(stdin);
			printf("\n Ingrese estado civil (C-casado, S-soltero, V-viudo, W-separado): ");
			scanf("%c", &estado);
			mostrar_informacion(vecD,vecC,vecES,vecED,M,estado);
			break;
		case 5: /*muestra la lista de miembros*/
			printf("\n Listado de miembros \n");
			mostrar_lista(vecD,vecC,vecES,vecED,M);
			break;
		default: printf("\n Opcion invalida. Intente nuevamente.");
		}
	} while(op!=0);
	return 0;
}

/*MODULOS*/

/*Modulo de menu*/

int menu(){
	int opc;
	printf("\n [0] SALIR");
	printf("\n [1] Verificar si DNI esta en la lista de miembros");
	printf("\n [2] Eliminar un miembro de la lista");
	printf("\n [3] Agregar nuevo miembro");
	printf("\n [4] Mostrar informacion de los miembros que indiquen mismo estado civil");
	printf("\n [5] Mostrar lista de miembros");
	printf("\n Ingrese opcion: ");
	scanf("%d", &opc);
	return opc;
}
/*Modulo que carga una lista y la ordena por dni a medida que se ingresan los datos. 
  Trabajo con las 4 listas a la vez*/
	
void cargar_lista(TLlista lisD,TLlista lisC,TClista lisEs,TIlista lisEd,int *m){
	int i,j,auxEd;
	long auxD,auxC;
	char auxEs;
	printf("\n Ingrese el tamaño de la lista: ");
	scanf("%d", m);
	printf("\n Ingrese DNI: ");
	scanf("%ld", &lisD[1]);
	printf("\n Ingrese Nro de celular: ");
	scanf("%ld", &lisC[1]);
	fflush(stdin);
	printf("\n Ingrese Estado Civil (C-casado, S-soltero, V-viudo, W-separado): ");
	scanf("%c", &lisEs[1]);
	printf("\n Ingrese Edad: ");
	scanf("%d", &lisEd[1]);
	for(i=2;i<=*m;i++){
		printf("\n Ingrese DNI: ");
		scanf("%ld", &auxD);
		printf("\n Ingrese Nro de celular: ");
		scanf("%ld", &auxC);
		fflush(stdin);
		printf("\n Ingrese Estado Civil (C-casado, S-soltero, V-viudo, W-separado): ");
		scanf("%c", &auxEs);
		printf("\n Ingrese Edad: ");
		scanf("%d", &auxEd);
		lisD[0]=auxD;
		j=i-1;
		while(auxD<lisD[j]){
			lisD[j+1]=lisD[j];
			lisC[j+1]=lisC[j];
			lisEs[j+1]=lisEs[j];
			lisEd[j+1]=lisEd[j];
			j=j-1;
		}
		lisD[j+1]=auxD;
		lisC[j+1]=auxC;
		lisEs[j+1]=auxEs;
		lisEd[j+1]=auxEd;
	}
}
	
/*Modulo que muestra la lista. Trabajo con las 4 listas a la vez*/
	
void mostrar_lista(TLlista lisD,TLlista lisC,TClista lisEs,TIlista lisEd,int m){
	int i;
	for(i=1;i<=m;i++){
		printf("\n Datos del miembro %d: ", i);
		printf("\n DNI: %ld", lisD[i]);
		printf("\n Nro de celular: %ld", lisC[i]);
		printf("\n Estado: %c", lisEs[i]);
		printf("\n Edad: %d", lisEd[i]);
	}
}
/*Modulo que realiza busqueda binaria pues la lista esta ordenada por dni. 
  Trabajo solo con la lista de dni*/
	
int busqueda_dni(TLlista lisD,int m,long nro){
	int ini,fin,med;
	ini=1;
	fin=m;
	med=(ini+fin)/2;
	while(ini<=fin && nro!=lisD[med]){
		if(nro<lisD[med])
			fin=med-1;
		else
			ini=med+1;
		med=(ini+fin)/2;
	}
	if(ini<=fin)
		return med;
	else
		return 0;
}
/*Modulo que elimina un miembro de la lista. Trabajo con las 4 listas a la vez*/
	
void eliminar(TLlista lisD,TLlista lisC,TClista lisEs,TIlista lisEd,int *m,int pos){
	int i;
	for(i=pos;i<=*m-1;i++){
		lisD[i]=lisD[i+1];
		lisC[i]=lisC[i+1];
		lisEs[i]=lisEs[i+1];
		lisEd[i]=lisEd[i+1];
	}
	*m=*m-1;
}
/*Modulo que agrega un miembro nuevo a la lista. Trabajo con las 4 listas a la vez*/
	
void agregar(TLlista lisD,TLlista lisC,TClista lisEs,TIlista lisEd,int *m,int pos,long nro,long cel,char est,int ed){
	int i;
	for(i=*m;i>=pos;i=i-1){
		lisD[i+1]=lisD[i];
		lisC[i+1]=lisC[i];
		lisEs[i+1]=lisEs[i];
		lisEd[i+1]=lisEd[i];
	}
	lisD[pos]=nro;
	lisC[pos]=cel;
	lisEs[pos]=est;
	lisEd[pos]=ed;
	*m=*m+1;
}
/*Modulo que muestra la informacion de los miembros cuyo estado coincidan con el estado ingresado. 
  Trabajo con las 4 listas a la vez*/
void mostrar_informacion(TLlista lisD,TLlista lisC,TClista lisEs,TIlista lisEd,int m,char est){
	int i;
	for(i=1;i<=m;i++){
		if(lisEs[i]==est){
			printf("\n DNI: %ld", lisD[i]);
			printf("\n Nro de celular: %ld", lisC[i]);
			printf("\n Estado civil: %c", lisEs[i]);
			printf("\n Edad: %d", lisEd[i]);
		}
	}
}
