#include <iostream>
#include "class_segui1b.h"

using namespace std;

int main(){
	int N;
	double x, expp; // definimos las vairables
	cout<<"Ingrese el orden al cual desea conocer el valor de e^x (N): "; // pedimos al usuario que ingrese los datos
	cin>>N;
	cout<< "Ingrese el valor de la serie, es decir, ingrese el valor de x: ";
	cin>>x;
	Euler serie = Euler(x,N);
	expp = serie.exponencial(x,N);
	
	// En caso de que desee conocer el factorial de un número, puede llamar la función de la siguiente forma
	// factorial = serie.Factorial(N);
	
	cout<< "El valor de e^"<<x<<", a orden "<< N<<", es: "<<expp<<endl; //imprimimos el resultado requerido por el usuario


	return 0;
}
