#include <iostream>
#include "facturas.h"

using namespace std;

int main()
{

    string numerodepieza_;
    string descripcion_;  
    int cantidadarticulos_;
    int precio_; //precio por articulo
    float total_;

    cout<<"Ingrese el número de la pieza = \n"; 
    cin>>numerodepieza_;
    
    cout<<"Ingrese la descripción del producto = \n"; 
    cin>>descripcion_;
    
    cout<<"Ingrese la cantidad de artículos = \n"; 
    cin>>cantidadarticulos_;
    
    cout<<"Ingrese el precio por unidad =\n";
    cin>>precio_;

    cout<<"Factura\n";
    Factura compra(numerodepieza_,descripcion_,cantidadarticulos_,precio_);
    compra.MontodeFactura();

    system("pause");
    return 0;

}


