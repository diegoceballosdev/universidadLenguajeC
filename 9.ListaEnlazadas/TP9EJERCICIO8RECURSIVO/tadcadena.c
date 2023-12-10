#include "tadcadena.h"
/**MODULOS PRIVADOS**/ 
void limpiabuffer (){
	char c ; 
	c=getchar () ; 
	if(c!=EOF&&c!='\n')
		limpiabuffer(); 
}
void leecad_recu (tcad v , int tam , int i){
	char c ; 
	c=getchar() ;
	if (i<tam-1 && c!='\n' && c!=EOF){
		v[i]=c; 
		leecad_recu(v,tam,i+1);
	}
	else {
		v[i]='\0';
		if(c!=EOF && c!='\n')
			limpiabuffer () ; 
	}
}
/**MODULOS PUBLICOS**/
void leecad (tcad v) {
	leecad_recu(v,MAX,0); 
}
