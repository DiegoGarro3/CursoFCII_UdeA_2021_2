#include "Factura.h"	


Factura::Factura(string innumero, string indescripcion, int incantidad, float inprecio){
  
  setnumber( innumero );
  setdescription( indescripcion);
  setquantity( incantidad );
  setcost( inprecio );
  calcularFactura();
}

//Funciones Establecer para los miembros de la clase
void Factura::setnumber(string innumero){
  number = innumero;
}
void Factura::setdescription(string indescription){
  description = indescription.substr( 0, 100 );
}
void Factura::setquantity( int incantidad){
  if(incantidad < 0){
    quantity = 0;
  }
  else{
    quantity = incantidad;
  }
  
}
void Factura::setcost(float inprecio){
  
  if(inprecio < 0){
    cost = 0;
  }
  else{
    cost = inprecio;
  }
}

//Funciones Obtener para los miembros de la clase
string Factura::getnumber(){
  return number;
}
string Factura::getdescription(){
  return description;
}
int Factura::getquantity(){
  return quantity;
}
float Factura::getcost(){
  return cost;
}


void Factura::calcularFactura(){
	total = quantity * cost;
}

void Factura::obtenerMontoFactura(){
  cout << "\nCosto Total de la factura $"<<total<<"\nDescripcion del articulo comprado: "<< getdescription()<<endl;
}

