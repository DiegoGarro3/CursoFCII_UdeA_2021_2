#include <iostream>
#include<iomanip>
#include<string>
using std::cout; 
using std::endl;
using std::cin;

#include "factura.h"

int main()
{
string a;
string b;
int c;
double d;

cout<<"Ingrese el numero de pieza"<<endl;
getline(cin,a);
cout<<"Ingrese la descripcion"<<endl;
getline(cin,b);
cout<<"Ingrese la cantidad"<<endl;
cin>>c;
cout<<"Ingrese el valor por unidad"<<endl;
cin>>d;
cout<<endl;
Factura factura2(a,b,c,d);
factura2.displayFactura();
};