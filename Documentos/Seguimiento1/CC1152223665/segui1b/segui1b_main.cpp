//Funcion principal uqe usa la clase Euler creada.

#include<iostream> //libreria para entrada y salida de datos.
#include "segui1b_clase.h" //se llama la clase creada.

using namespace std;

int main(){ //funcion principal.
	
	//declaracion de variables.
	int N; 
	double x,expp,facto;
	
	//se imprime y se pide ingresar por pantalla el orden de la suma "N", y el valor al cual calcular la exponencial "x".
	cout<<"ingrese hasta que orden N: "; 
	cin>>N;
	cout<<"ingrese x: ";
	cin>>x;
	
	Euler euler=Euler(x,N); //se declara euler como un elemento de la clase creada con sus respectivos atributos o variables que la clase 										//usa internamente para entregar los resultados.
	
	expp=euler.Exponencial(x,N); //se llama el metodo Exponencial de la clase y se almacena el resultadoe en una variable.
	
	facto=euler.Factorial(N);
	
	cout<<"e^x= "<<expp<<endl; //se imprime en pantalla el valor calculado por el metodo.
	cout<<"N!= "<<facto<<endl;
	return 0; //se retorna un entero por la funcion principal.
}
