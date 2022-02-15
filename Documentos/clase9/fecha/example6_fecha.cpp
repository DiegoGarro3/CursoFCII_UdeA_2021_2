#include <iostream>

using namespace std;

#include "fecha.h"

int main()
{
  Fecha fecha1( 7, 4, 2004 );
  Fecha fecha2;
  
  cout << "fecha1 = ";
  fecha1.imprimir();
  cout << "\nfecha2 = ";
  fecha2.imprimir();
  
  fecha2 = fecha1;
  cout << "\n\nDespues de la asignacion predeterminada a nivel de bits, fecha2 = ";
  fecha2.imprimir();
  cout << endl;
  
  return 0;
}
