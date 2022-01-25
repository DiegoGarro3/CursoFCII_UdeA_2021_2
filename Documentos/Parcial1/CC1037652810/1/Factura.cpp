#include <iostream>
#include "Factura.h"
#include <iomanip>

using namespace std;


Factura::Factura( string piecenum, string piecedesc, int amount, int price)
{
  establecerNum( piecenum );
  establecerDesc( piecedesc ); 
  setAmount( amount ); 
  setPrice( price );  
} 

void Factura::establecerNum( string numero )
{
    pnum = numero; 
} 
string Factura::obtenerNum()
{
  return pnum;
} 

void Factura::establecerDesc( string desc )
{
    pdesc = desc; 
} 
string Factura::obtenerDesc()
{
  return pdesc;
} 

void Factura::setAmount( int amount )
{
  if ( amount >= 0 ) 
    cantidad = amount; 
  else 
    { 
      cantidad = 0; 
      cout << "La cantidad \"" << amount << "\" no es una cantidad valida.\n" << endl;
    } 
} 
int Factura::obtainAmount()
{
  return cantidad;
} 

void Factura::setPrice( int price )
{
  if ( price >= 0 ) 
    precio = price; 
  else 
    { 
      precio = 0; 
      cout << "El precio \"" << price << "\" no es un valor valido.\n" << endl; 
    }
} 

int Factura::obtainPrice()
{
  return precio;
} 

void Factura::mostrarMensaje()
{
cout << setw(27) << left << "Identificacion del producto:" << setw(35) << right << obtenerNum() << "\n" << setw(27) << left << "Descripcion:" << setw(36) << right << obtenerDesc() << "\n" << setw(27) << left << "Cantidad:" << setw(36) << right <<  obtainAmount() << "\n" << setw(27) << left << "Precio por unidad:" << setw(35) << right << obtainPrice() << "$" << endl;
}



int Factura::ObtenerMontoFactura()
{ 
  int total=0;
  total=cantidad*precio;
  return total;
}

void Factura::mostrartotal()
{
  cout << setw(27) << left <<"El total es: " << setw(35) << right << ObtenerMontoFactura() << "$ \n \n" << endl;
} 



