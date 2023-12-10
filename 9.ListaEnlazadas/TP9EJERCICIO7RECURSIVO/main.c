#include "tad_lis.h" 
void opciones ();
void menu (Tlista*); 
int main (){
	Tlista lista ; 
	inicializa (&lista); 
	menu(&lista); 
	return 0 ; 
}
void opciones () {
	printf ("\n====OPCIONES DEL MENU====\n"); 
	printf ("\nINGRESE 1:AGREGE ALUMNO");
	printf ("\nINGRESE 2:MOSTRAR ALUMNO");
	printf ("\nINGRESE 3:ELIMINAR ALUMNO");
	printf ("\nINGRESE 4:MOSTRAR LISTA") ; 
	printf ("\nINGRESE 0:SALIR DEL MENU"); 
}
void menu (Tlista *lis){
	int rta ; 
	opciones();
	printf ("\nINGRESE SU ELECCION: ");
	scanf ("%d",&rta);
	switch (rta){
	case 0 : 
		printf ("\nFIN DEL PROGRAMA");
		break ; 
	case 1:
		agrega_alumno(lis) ; 
		menu(lis);
		break ; 
	case 2:
		MuestraAlumno(*lis);
		menu(lis);
		break ; 
	case 3:
		Eliminar_Alumno(lis);
		menu(lis);
		break ; 
	case 4 :
		Muestra_Lista(*lis) ; 
		menu(lis);
		break ; 
	default :
		printf ("\nOpciones Inexistente");
	    menu(lis); 
	}
}
