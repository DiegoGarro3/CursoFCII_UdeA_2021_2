#include <iostream>
#include<iomanip>
using std::cout; 
using std::endl;

#include "factura.h"
using namespace std;

int main()
{
    Factura factura1( "1027234","ladrillo 10x20",-3, 3000.00);
    cout<< "numero de pieza: "<<factura1.getnumpieza()<<endl;
    cout<<"Descipcion: " << factura1.getdescripcion()<< endl;
    cout<< "Cantidad: " << factura1.getcantidad()<< endl;
    cout<< "Valor por unidad: "<<fixed<<setprecision(2)<<factura1.getvalor()<< endl;
    cout<< "Total a pagar: "<<fixed<<setprecision(2)<<factura1.obtenerMontoFactura()<< endl;
    cout<< endl;

    //lo anterior pero ahora usando la funcion  displayFactura()
    factura1.displayFactura();


    return 0;
}