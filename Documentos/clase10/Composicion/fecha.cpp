#include <iostream>
#include "fecha.h"

using namespace std;

Fecha::Fecha( int mm, int dd, int aa )
{
  if ( mm > 0 && mm <= 12 ) // valida el mes
    mes = mm;
  else
    {
      mes = 1; // mes inválido se establece en 1
      cout << "Mes invalido (" << mm << ") se establecio en 1.\n";
    }
  
  anio = aa; // se pudo validar aa?
  dia = comprobarDia( dd ); // valida el dia
  
  // imprime objeto Fecha para mostrar cuándo se llama a su constructor
  cout << "Constructor del objeto Fecha para fecha ";
  imprimir();
  cout << endl;
}

void Fecha::imprimir() const
{
  cout << mes << '/' << dia << '/' << anio;
}

// imprime objeto Fecha para mostrar cuándo se llama a su destructor
Fecha::~Fecha()
{
  cout << "Destructor del objeto Fecha para fecha ";
  imprimir();
  cout << endl;
}

// función utilitaria para confirmar el valor de dia apropiado con base
// en mes y anio; maneja años bisiestos también
int Fecha::comprobarDia( int diaPrueba ) const
{
  static const int diasPorMes[ 13 ] =
    
  { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
  
  // determina si diaPrueba es válido para el mes especificado
  if ( diaPrueba > 0 && diaPrueba <= diasPorMes[ mes ] )
    return diaPrueba;
  
  // comprueba 29 de febrero para año bisiesto
  if ( mes == 2 && diaPrueba == 29 && ( anio % 400 == 0 ||
					( anio % 4 == 0 && anio % 100 != 0 ) ) ){
    return diaPrueba;
  }
  
  cout << "Dia invalido (" << diaPrueba << ") se establecio en 1.\n";
  return 1; // deja el objeto en estado consistente si hay un valor incorrecto
}
    
