#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

class Factura
{
public:

  Factura(string N,string O, int C,float P); //Constructor de las clases que iniciliaza las 4 variables
  void setObject(string O); //Funcion Establecer

  string getObject(); //Funcion obtener

  void setNumber(string N);

  string getNumber();

  void setCanti(int C);
  
  int getCanti();

  void setPrecio(float P);

  float getPrecio();

  void Display(); //Funcion con el outpout del programa

  int obtenerMontoFactura(); //Funcion para obtener el valor total
 
  
 private:
  
  string Object;
  string Number;
  int Canti;
  int Precio;


};
