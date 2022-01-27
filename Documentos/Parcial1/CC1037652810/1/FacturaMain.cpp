#include <iostream>
#include "Factura.h"

using namespace std;

int main()
{
  cout << "Ferreteria abc \n" << endl;

  Factura compra1( "Pieza # 2", "Martillo de hierro", 4, 15000 );
  compra1.mostrarMensaje();
  compra1.mostrartotal();

  Factura compra2( "Pieza # 10", "Destornillador de acero inoxidable", -2, -16000 );
  compra2.mostrarMensaje();
  compra2.mostrartotal();

return 0; 
}
