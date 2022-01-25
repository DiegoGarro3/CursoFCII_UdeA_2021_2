/*
Santiago Quintero Cordoba 

Parcial 1
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Factura{//Creacion de una clase llamada exponencial

    public://Declaracion de las funciones publicas
        
        Factura();//Constructor de la clase

        //En Factura.cpp se halla una breve descripcion de lo que hace cada funcion
        void Establecer_pieza(string);
        void Establecer_descripcion(string);
        void Establecer_cantidad(unsigned  int);
        void Establecer_valor(long int);

        long int Obtener_valor();
        unsigned int Obtener_cantidad();
        string Obtener_descripcion();
        string Obtener_pieza();

        unsigned long int obtenerMontoFactura();

    private://Declaracion de las variables privadas
    
        string pieza;
        string descripcion;
        unsigned  int cantidad;//como el valor no tiene signo entonces no es necesario hacer el caso cuando la cantidad es negativa
        long int valor;
};