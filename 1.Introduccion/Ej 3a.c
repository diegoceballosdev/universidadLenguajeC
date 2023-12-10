#include <stdio.h>  //Encabezado del programa

//Funcion principal:

int main() { 
	int x, aux, s, d, b, c; //Declaracion de variables
	c=0;
	printf("\n ingrese natural"); 
	scanf("%d" ,&x); //Dato de entrada
	while (x>0){ //Ciclo condicionado
		aux=x; 
		s=0;
		while(x!=0){ //Ciclo condicionado,Separacion de digitos y suma de ellos
			d=x%10; 
			s=s+d; 
			x=x/10; 
		}
		x=aux; 
		b=0;
		while ((x!=0)&&(b==0)){ //Ciclo condicionado
			d=x%10;
			if (d!=0 && s%d!=0) //Sentencia de control
				b=1;
			else 
			x=x/10; 
		}
		if (b==0) //Sentencia de control
				c=c+1; 
			printf("\n ingrese natural"); //Dato de salida
			scanf("%d",&x); //Dato de entrada
	}
	if (c==0)  //Sentencia de control
		printf("\n ninguno cumple"); //Dato de salida
	else 
		printf("\n cumplen %d",c); //Dato de salida
	return 0; 
}
/* El programa permite ingresar numeros naturales
con la condicion de que sus digitos sean distintos de cero y donde el 
"resto" entre la suma de estos digitos y cada digito individual,sea cero 
Un contador llevara la cuenta de los num que cumplieron estas condiciones*/
