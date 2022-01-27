#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include "Factura.h"



//Constructor que inicializa los 4 valores de la factura
Factura::Factura(string N,string O, int C,float P){
    setNumber(N);
    setObject(O);
    setCanti(C);
    setPrecio(P);
  }


void Factura::setObject(string O){
    
  Object= O; //Establecer objeto
}

string Factura::getObject(){
    
  return Object; //Obtener Objeto
}

void Factura::setNumber(string N){
  
  Number= N; //Establecer numero pieza
}

string Factura::getNumber(){
  
  return Number; //Obtener numero pieza
}

void Factura::setCanti(int C){
  Canti=C; //Establecer Cantidad
}

int Factura::getCanti(){
  
  return Canti; //Obtener Cantidad
}

void Factura::setPrecio(float P){
  Precio= P;
}

float Factura::getPrecio(){
  
  return Precio; //Obtener Precio de cada articulo
  }


//Salida de el programa 
void Factura::Display()
{
   
  
  cout << setw(4) << fixed << "#" << setw(30) << fixed  <<  " Objeto" << setw(20) << fixed <<   " Cantidad" << setw(20) << fixed <<     "Valor(c/u)" << setw(20) << fixed <<    " Valor Total" << endl;
  
  cout  << setw(4) << fixed << "---" << setw(30) << fixed << "-----------------------" << setw(20) << fixed << "----------" << setw(20) << fixed << "----------"<< setw(20) << fixed << "-----------" << endl;
  
  cout  << setw(4) << fixed <<  Number << setw(30) << fixed << Object << setw(20) << fixed << Canti << setw(20) << fixed << Precio << setw(20) << fixed << obtenerMontoFactura() << endl;
       
}

//Valor Total de la maftura
int Factura::obtenerMontoFactura()
{
  int Monto;
  
  Monto=Canti*Precio;
  
  if (Canti<0){
    return 0;
    
  }
  
  if(Monto<0){
    
    return 0;
    
  }
  
  return Monto;
}
