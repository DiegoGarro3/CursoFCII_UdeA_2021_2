#include <iostream>
using namespace std;

#include "fecha.h"

Fecha::Fecha( int m, int d, int y )
{
  mes = m;
  dia = d;
  anio = y;
}

// imprime la Fecha en el formato mm/dd/aaaa
void Fecha::imprimir()
{
  cout << mes << '/' << dia << '/' << anio;
}


