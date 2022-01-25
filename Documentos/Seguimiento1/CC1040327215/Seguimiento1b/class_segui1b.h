#include<iostream>
#include <math.h>

using namespace std;

class Euler{ //creamos la clase, le damos el nombre de Euler
	private:
		double x; // estas variables solo serán utilizadas por la clase, le damos un carácter privado como no lo pide el ejercicio
		int N;
	public:
		Euler(double,int); // definimos las funciones publicas, las que serán utilizadas por el usuario
		double Factorial(int); // el factorial, dado que es un número grande, lo ponemos como un double y recibirá solamente enteros positivos
		double exponencial(double,int); // la función exponencial recibirá el valor de x (valor real) y el valor de corte de la serie
						// el cual es un entero positivo.

};


