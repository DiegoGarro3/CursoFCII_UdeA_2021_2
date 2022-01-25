#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "facturas.h"

using namespace std;
using std::time;

Factura::Factura(string _numerodepieza,string _descripcion,int _cantidadarticulos,float _precio){
    numerodepieza = _numerodepieza;
    descripcion = _descripcion;
    cantidadarticulos = _cantidadarticulos;
    precio = _precio;
}

void Factura::MontodeFactura(){


    if (cantidadarticulos < 0){
        cout<<"Si la cantidad no es positiva, debe establecerse en cero";
        cantidadarticulos = 0;
      }

    if (precio < 0){
        cout<<"Si el precio por artículo no es positivo, debe establecerse en cero";
        precio = 0;
        }
    total = cantidadarticulos * precio;

    cout<<"Número de piezas : "<<numerodepieza<<endl;
    cout<<"Descripción de la pieza : "<<descripcion<<endl;
    cout<<"Cantidad de artículos comprados : "<<cantidadarticulos<<endl;
    cout<<"precio por cada producto : "<<precio<<endl;

    if (cantidadarticulos>0 and precio>0) 
        cout<<"El monto total es = "<<total<<endl;}


