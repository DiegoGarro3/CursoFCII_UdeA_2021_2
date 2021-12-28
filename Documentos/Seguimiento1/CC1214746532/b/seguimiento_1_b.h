/*
Codigo seguimiento 1b, creacion de la clase
Santiago Quintero Cordoba 
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class exponencial{//Creacion de una clase llamada exponencial

    public://Declaracion de las funciones publicas
        
        exponencial();//Constructor de la clase
        unsigned  int factorial(unsigned int);//Funcion que recibe un entero positivo
        																			//y devuelve un entero positivo
        double e();//Funcion que devuelve un doble
        void mostrar();//Funcion que no devuelve ningun tipo de dato

    private://Declaracion de las variables privadas
    
        unsigned int N;//Variable cuyo valor es un entero postivo
        double x;//Variable de valor doble
};
