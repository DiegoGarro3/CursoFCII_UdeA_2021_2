#include <iostream>
#include "class_segui1b.h" // incluimos la clase que hemos creado anteriormente

using namespace std;

Euler::Euler(double _x, int _N){ //creamos nuestro constructor
	x = _x; // datos que recibirá el constructor
	N = _N;
}

double Euler::Factorial(int N){ // construimos el factorial
	double fact; // nuestro fact será el que nos guardará el factorial del número N, lo ponemos como un double dado que será un numero grande
	int i; // declaramos el "contador"
	fact = 1; // inicializamos el factorial por medio de recurrencia
	
	if (N==0 || N==1){ // definición de 1 y 0 factorial
		return 1;
	}
	else{
		for(i=1;i<=N;i++){// creamos la recurrencia con un for
			fact = fact*i;
		}
		
		return fact;// retornamos el factorial del número N
	
	}

}

double Euler::exponencial(double x, int N){ // construimos la exponencial, recibiremos un double y un entero
	double contador; // declaramos el contador que irá sumando los N primeros términos de la serie
	int i;// declaramos el "contador"
	for(i=0; i<=N;i++){ // con este for iremos recorriendo los N terminos
		contador += pow(x,i)/Euler::Factorial(i); // acá empezamos a sumar esos N términos que le usuario desea
	}
	return contador;// retornamos el valor de la suma de los N términos de e^x
	
}
