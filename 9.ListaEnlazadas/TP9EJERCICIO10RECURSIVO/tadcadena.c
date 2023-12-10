#include "tadcadena.h" 
/**MODULO PRIVADO**/
void limpiabuffer(){
	char c ; 
	c=getchar(); 
	if (c!=EOF && c!='\n')
		limpiabuffer(); 
}
void leecad_rec (tcad v , int i , int tam){
	char c ; 
	c=getchar() ; 
	if (i<tam-1 && c!=EOF && c!='\n'){
		v[i]= c ; 
		leecad_rec (v,i+1,tam) ; 
	}
	else{
		v[i]='\0' ; 
		if (c!=EOF && c!='\n')
			limpiabuffer(); 
	}
} 
/**MODULO PUBLICO**/ 
void leecad (tcad v ){
	leecad_rec(v,0,TAMA) ; 
}
