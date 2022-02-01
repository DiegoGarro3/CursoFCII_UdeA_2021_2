#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

  string cadena1 = "El aeroplano despego en rionegro.";
  
  // obtiene la subcadena "plano" que empieza en el subíndice 7 y consiste de 5 caracteres
  cout << cadena1.substr( 7, 5 ) << endl;

  cout << endl;
  
  string A1( "uno" );
  string A2( "dos" );
  // imprime los objetos string
  cout << "Antes de swap:\nA1: " << A1 << "\nA2: " << A2;
  A1.swap( A2 ); // intercambia los objetos string
  cout << "\n\nDespues de swap:\nA1: " << A1
       << "\nA2: " << A2 << endl;
  
return 0; 
}  
  
