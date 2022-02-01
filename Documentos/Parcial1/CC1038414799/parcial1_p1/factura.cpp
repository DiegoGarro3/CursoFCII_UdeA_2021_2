#include <iostream>
#include <iomanip>

using namespace std;

#include "factura.h"

Factura::Factura(string _pieceRef, string _pieceName, unsigned int _cant, float _price)
{
  pieceRef=_pieceRef; //initialize item reference 
  pieceName=_pieceName; //initialize item description
  cant=_cant; //initialize number of items
  price=_price; //initialize price of the item

}

//Function to set item reference
void Factura::setPiece(string _pieceRef)
{  
  pieceRef=_pieceRef;

}

//Function to obtain item reference
string Factura::getPiece()
{
  return pieceRef; 
}


//Function to set item description
void Factura::setDescri(string _pieceName)
{  
  //cut description to 24 chars
  if ( _pieceName.length() <= 24 ) 
    pieceName = _pieceName; 
  else 
    { 
      //cut description to 24 chars
      pieceName = _pieceName.substr( 0, 24 );
    } 

}

//Function to obtain item description
string Factura::getDescri()
{
  return pieceName; 
}



//Function to set number of items
void Factura::setArticles(int _cant)
{  
  cant= _cant;

}

//Function to obtain number of items
int Factura::getArticles()
{
  return cant; 
}

//Function to set item price
void Factura::setPrice(float _priece)
{  
  price= _priece;

  //set item price to 0 if it's negative
  if(price < 0)
    price = 0;

}

//Function to obtain item price
float Factura::getPrice()
{
  return price; 
}

//Function to return the bill
float Factura::ObtenerMontoFactura()
{
  //total=price*#_of_items
  float monto = getArticles()*getPrice();
  //set total to 0 if it's negative
  if(monto < 0)
    monto = 0;
  
  return monto;
}

//print the bill on the screen
void Factura::printBill()
{

  cout << "|" << "# Pieza"<< "|" 
  << setw(25) << fixed << "Descripción" << "|" 
  << setw(15) << fixed << "Precio unidad" << "|"
  << setw(10) << fixed << "Cantidad" << "|"
  << setw(20) << fixed << "Monto factura" << "|"
  << endl;
  
  cout << "----------------------------------------------------------------------------------" 
  << endl;
  
  
  
  cout << "|" << setw(7) << fixed  << getPiece() << "|"
  << setw(24) << fixed << getDescri() << "|"
  << setw(15) << fixed << setprecision(2) << getPrice() << "|"
  << setw(10) << fixed << getArticles() << "|"
  << setw(20) << fixed << setprecision(2) << ObtenerMontoFactura() << "|"
  << endl;

}






