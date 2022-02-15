#include <iostream>
#include "Incremento.h"

using namespace std;

int main()
{
  Incremento valor( 10, 5 );
  
  cout << "Antes de incrementar: ";
  valor.imprimir();
  
  for ( int j = 1; j <= 3; j++ )
    {
      valor.agregarIncremento();
      cout << "Despues de incrementar " << j << ": ";
      valor.imprimir();
    }
  
  return 0;
}
