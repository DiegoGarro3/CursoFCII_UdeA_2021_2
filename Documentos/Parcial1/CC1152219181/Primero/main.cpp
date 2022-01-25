
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include "Factura.h"

int main()
{
  //Definicion delas 4 caracteristicas que tiene una factura
  string Numero;
  string Objeto;
  int Cantidad;
  float Valor;
  
  //Ejemplo de lo que sera el objeto.
  Factura Sierra("02","Sierra Electrica",2,100000);
  
  cout << "Ejemplo de lo que puede hacer la clase Factura" << endl;
  cout << "\n";
  Sierra.Display();
  cout << "\n";
  cout << "\n";
  cout << "\n";
  cout << "Ahora interactue con el programa y cree su propia factura" << endl;
  cout << "\n";
  cout << "\n";
  
  cout << "Ingrese el numero de pieza: ";
  //Ingresa el numero de pieza que se compran.
  getline(cin, Numero);
  cout << "\n";
  
  
  //El usuario ingresa el objeto que se compra
  cout<<"Ingrese el Objeto/Descripcion: ";
  getline(cin,Objeto);
  cout << "\n";
  
  //El usuario ingresa el numero de articulos que se compran
  cout<<"Ingrese la Cantidad: ";
  cin >> Cantidad;
 cout << "\n";
  
//El usuario ingresa el valor de el articulo
 cout << "Valor c/u :";
 cin >> Valor;
  cout << "\n";
  cout << "\n";
  cout << "\n";

  //Cracion del objeto con los datos ingresados por el usuario
  Factura Usuario(Numero,Objeto,Cantidad,Valor);
  //Impresion dela factura creada por el usuario
  Usuario.Display();
  
  return 0;
}
