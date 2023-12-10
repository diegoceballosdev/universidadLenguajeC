/*Para Ejercicio 10: Un canal de cable necesita manejar dos listas, la primera será 
una lista de pedidos diarios de reparación y la segunda, una lista de los pedidos 
de reparación resueltos, de sus abonados. Los datos que registra por cada pedido 
ingresado son: Nº de Pedido, Nº de Abonado, Descripción del problema, fecha.
Se pide crear un programa que a través de un menú permita: agregar un nuevo
pedido de reparación; dado un Nº de Pedido, quitarlo de la lista de pedidos 
de reparación ingresados y ubicarlo en la lista de pedidos de reparación resueltos; 
listar todos los pedidos de reparación, aún sin resolver y dada una fecha, 
listar todos los pedidos de reparación resueltos en esa fecha.

*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_CAD 30
typedef char Tcad[MAX_CAD];

typedef struct{
	int codigo;
	int abonado;
	Tcad descripcion;
	int fecha;
}t_Pedido;

typedef struct Nodo{
	t_Pedido dato;
	struct Nodo* sig;
}t_Nodo;
typedef t_Nodo* tPunteroNodo;

/** Prototipos t_Nodo (Registro)*/
t_Pedido crea_pedido();
void muestra_pedido(t_Pedido);
int compara_pedido(t_Pedido, int);
int ingresa_cod();
int compara_fecha(t_Pedido, int);

/** Prototipos LE */
/*Crear un nodo: crea un nodo con el dato cargado y el campo sig con valor NULL*/
tPunteroNodo crea_nodo();
void muestra_nodo(tPunteroNodo);
tPunteroNodo crea_lista_vacia();
/*Mostrar todos los pedidos*/
void muestra_lista(tPunteroNodo);
/*agrega al final de la lista*/	
void agrega_pedido(tPunteroNodo*);
void agrega_final(tPunteroNodo*,tPunteroNodo);
/*saca y retorna un nodo aislado*/	
void saca_pedido(tPunteroNodo*,tPunteroNodo*,int);
int buscar_nodoxcod(tPunteroNodo ,int);
void atender_pedido(tPunteroNodo *,tPunteroNodo *);

/*muestra todos los pedidos de una fecha dada*/
/*void muestra_resuelto_fecha(tPunteroNodo);*/

/** Prototipo TCad*/
void leeCad(Tcad, int);

/** Otros*/
int menu(void);

/** MAIN*/
int main(int argc, char *argv[]) {
	tPunteroNodo l_repara,l_resuelto;
	int op;
	
	l_repara=crea_lista_vacia();
	l_resuelto=crea_lista_vacia();
	do{
		op=menu();
		switch (op){
		case 1:
			agrega_pedido(&l_repara);
			break;
		case 2:
			atender_pedido(&l_repara,&l_resuelto);
			break;
		case 3: 
			muestra_lista(l_repara);
			break;
		case 4: 
			muestra_lista(l_resuelto);
			break;
		case 0: 
			printf("\nSaliendo.......");
			break;
		default: 
			printf("\nLa opcion ingresada es incorrecta");
		}	
	}while (op!=0);
	return 0;
}

/** IMPLEMENTACION*/
void leeCad(Tcad cadena, int tam){
	int j, m;
	j=0;
	while(j<tam-1 && (m=getchar())!=EOF && m!='\n'){
		cadena[j]=m;
		j++;
	}
	cadena[j]='\0';
	if(m != EOF && m != '\n') /*limpia el buffer*/
		while((m=getchar())!=EOF && m!='\n');
}
int menu(void){
	int r;
	printf("\n-----Menu-----");
	printf("\n1- Agrega un pedido");
	printf("\n2- Resuelve un pedido");
	printf("\n3- Muestra Pedidos");
	printf("\n4- Muestra Pedidos Resueltos");
	printf("\n0- Salir");
	printf("\nIngrese una opcion: ");
	scanf("%d",&r);
	return r;
}	
	
/** REGISTRO  t_Pedido */	
	
t_Pedido crea_pedido(){
	t_Pedido p;
	printf("\nIngrese el Nro de Pedido: ");
	scanf("%d",&p.codigo);
	printf("\nIngrese el Nro de Abonado: ");
	scanf("%d",&p.abonado);		
	printf("\nIngrese la descripcion: ");
	fflush(stdin);
	leeCad(p.descripcion,MAX_CAD);
	printf("\nIngrese la fecha: ");
	scanf("%d",&p.fecha);
	return p;
}

int compara_pedido(t_Pedido p, int cod){
	if (p.codigo > cod) return 1;
	 else if (p.codigo < cod) return -1;
		else return 0;
}

int compara_fecha(t_Pedido p, int fech){
	if (p.fecha > fech) return 1;
		else if (p.fecha < fech) return -1;
			else return 0;
}
	
int ingresa_fecha(){
	int fech;
	printf("\nIngrese la fecha: ");
	scanf("%d",&fech);
	return fech;
}
	
void muestra_pedido(t_Pedido p){
	printf("\nNro de Pedido: %d", p.codigo);
	printf("\nNro de Abonado: %d", p.abonado);
	printf("\nDescripcion: %s", p.descripcion);
	printf("\nFecha: %d", p.fecha);
}

/** Lista Enlazada*/

tPunteroNodo crea_lista_vacia(){
	return NULL;
}
	
/*Crear un nodo: crea un nodo con el dato cargado y el campo sig con valor NULL*/
tPunteroNodo crea_nodo(){
	tPunteroNodo nodo = NULL;/*crea un puntero a una estructura tNodo*/

	nodo = (t_Nodo*) malloc(sizeof(t_Nodo));
	nodo->dato=crea_pedido();
	nodo->sig = NULL;/*Coloca nula la direccion de memoria del proximo nodo*/

	return nodo;
}

/*Muestra el dato del nodo*/
void muestra_nodo(tPunteroNodo nodo){
	muestra_pedido(nodo->dato);
}

/*Mostrar la lista*/
void muestra_lista(tPunteroNodo pun){
	if (pun==NULL)
		printf("Lista vacia\n");
	else 
		while (pun!=NULL){
			muestra_nodo(pun);
			pun=pun->sig;
		}
}
	
/*agrega al final de la lista*/	/**VER EN CLASE*/
void agrega_final(tPunteroNodo* cabeza,tPunteroNodo nuevo){
	tPunteroNodo aux;
					
	if (*cabeza==NULL) 
		*cabeza=nuevo;
	else{
		aux=*cabeza;
		while(aux->sig!=NULL)
			aux=aux->sig;
		aux->sig = nuevo;
		}
}
	
/* crea nodo y lo agrega al final de la lista*/
void agrega_pedido(tPunteroNodo* cabeza){
	tPunteroNodo uno;
	uno=crea_nodo();	
	agrega_final(cabeza,uno);	
}
	
/*saca y retorna un nodo aislado - OPCION 2*/	
/*	tPunteroNodo ant, aux;

	if (*cabeza!=NULL){
		if (compara_pedido((*cabeza)->dato, cod)==0){
			aux=*cabeza;
			*cabeza=(*cabeza)->sig;
		}
		else{	
			aux=*cabeza;
			while (aux!=NULL && compara_pedido(aux->dato, cod)!=0){
				ant=aux;
				aux = aux->sig;
			}
			if (aux!=NULL)
				ant->sig=aux->sig;
		}
		aux->sig=NULL;
		*sale=aux;
	}
	else *sale=NULL;
}*/
	
/*saca y retorna un nodo aislado*/ /** VER EN CLASE*/
void saca_pedido(tPunteroNodo* cabeza,tPunteroNodo* sale,int cod){
	tPunteroNodo ant, aux;
	
	if (*cabeza!=NULL){
		aux=*cabeza;
		ant=NULL;
	    while (aux!=NULL && compara_pedido(aux->dato, cod)!=0){
			ant=aux;
			aux = aux->sig;
	    }
	    if (ant!=NULL)
			ant->sig=aux->sig;
	    else
			*cabeza=(*cabeza)->sig;
		aux->sig=NULL;
	    *sale=aux;
	}	
	else *sale=NULL;
}

/* indica si existe pedido con un nro dado*/			
int buscar_nodoxcod(tPunteroNodo cab,int cod){
	if (cab!=NULL){	
		while (cab!=NULL && compara_pedido(cab->dato, cod)!=0)				
			cab = cab->sig;
		if (compara_pedido(cab->dato, cod)==0) 	return 1;
		else return 0;	
	}
	else return 0;
}

/*  quita, de la lista de pedidos, al pedido con nro ingresado 
	y lo agrega a la lista de pedidos resueltos*/
void atender_pedido(tPunteroNodo *pedidos,tPunteroNodo *resueltos){
	int cod;tPunteroNodo uno=NULL;
	
	printf("\nIngrese el Nro de Pedido: ");
	scanf("%d",&cod);
	
	if(buscar_nodoxcod(*pedidos,cod)==1){
		saca_pedido(pedidos, &uno, cod);	 
		agrega_final(resueltos,uno);
	}
	else 
	   printf("\nNo existe pedido con el Nro ingresado");
}

