#include <stdio.h>

int main(int argc, char *argv[]) {
	

limpia(){
	char c;

	if ((c=getchar())!=EOF && c!='\n')
		limpia();
}

leeCadRec(Tcad cadena, int tam, inyt pos){
	char c;
	
	if (pos<tam && (c=getchar())!=EOF && c!= '\n'){
		cadena[pos] = c;
		leeCadRec(cadena, tam, pos+1);
	}
	else
		cad[pos] = '\0';
	
	if (c!=EOF && c!='\n')
		limpia();
}
	
	

	return 0;
}

