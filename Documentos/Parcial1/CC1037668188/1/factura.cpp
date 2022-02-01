#include <iostream>
#include<iomanip>
using std::cout; 
using std::endl;

#include "factura.h"


Factura::Factura(string npieza ,string des ,int cant, double val)    // Constructor
{
    setnumpieza(npieza);
    setdescripcion(des);
    setcantidad(cant);
    setvalor(val);
};
// Implementacion funciones Establecer
void Factura::setnumpieza(string npieza)
{
    numeroDePieza=npieza;
};
void Factura::setdescripcion(string des)
{
    descripcion=des;
};
void Factura::setcantidad(int can)
{
    if(can<=0)
    cantidad=0;
    else
    cantidad=can;
};
void Factura::setvalor(double val)
{
    if(val<=0)
    valor=0;
    else
    valor=val;
    
};
// Implementacion Funciones Obtener
string Factura::getnumpieza()
{
    return numeroDePieza;
};
string Factura::getdescripcion()
{
    return descripcion;
};
int Factura::getcantidad()
{
    return cantidad;
};
double Factura::getvalor()
{
    return valor;
};
// Implementacion funcion obtenerMontoFactura
double Factura::obtenerMontoFactura()
{
    double ValorFactura;
    ValorFactura= getvalor()*getcantidad();
    return ValorFactura;
};
// Implementacion de la funcion displayFactura
void Factura::displayFactura()
{
    cout<<"Numero de pieza: "<<getnumpieza()<<endl;
    cout<<"Descripción: "<<getdescripcion()<<endl;
    cout<<"Cantidad: "<<getcantidad()<<endl;
    cout<< "Valor por unidad: "<<getvalor()<< endl;
    cout<< "Total a pagar: "<<obtenerMontoFactura()<< endl;
    cout<<endl;


};