#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  string cadena1( "Prueba de los iteradores" );
  string::const_iterator iterador1 = cadena1.begin();
  
  cout << "cadena1 = " << cadena1
       << "\n(Usando el iterador iterador1) cadena1 es: ";
  // itera a través del objeto string
  while ( iterador1 != cadena1.end() )
    {
      cout << *iterador1; // desreferencia el iterador para obtener un char
      iterador1++; // avanza el iterador al siguiente char
    } // fin de while
  cout << endl;
  
  
  return 0; 
}  
