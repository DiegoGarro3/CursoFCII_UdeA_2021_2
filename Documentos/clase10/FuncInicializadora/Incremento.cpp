#include <iostream>
#include "Incremento.h"

using namespace std;

// constructor
Incremento::Incremento( int c, int i )
: cuenta( c ), // inicializador para un miembro no const
  incremento( i ) // inicializador REQUERIDO para un miembro const
{
// cuerpo vacío
}

/*
Incremento::Incremento( int c, int i )
{
cuenta = c; // se permite, ya que cuenta no es constante
incremento = i; // ERROR: no se puede modificar un objeto const
}
*/

//donde esta la funcion "agregarIncremento"?

void Incremento::imprimir() const
{
cout << "cuenta = " << cuenta << ", incremento = " << incremento << endl;
}
