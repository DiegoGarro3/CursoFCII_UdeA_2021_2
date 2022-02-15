#include <iostream>
#include "time.h"

using namespace std;

int main(){
  
  Tiempo t; 
  
  // imprime los valores iniciales del objeto Tiempo t
  cout << "El tiempo universal inicial es ";
  t.imprimirUniversal(); // 00:00:00
  
  cout << "\nEl tiempo universal estandar es ";
  t.imprimirEstandar(); // 12:00:00 AM
  
  t.establecerTiempo( 13, 27, 6 ); // cambia el tiempo
  cout << "\n\nEl tiempo universal despues de establecerTiempo es ";
  t.imprimirUniversal(); // 13:27:06
  cout << "\nEl tiempo estandar despues de establecerTiempo es ";
  t.imprimirEstandar(); // 1:27:06 PM

  
  t.establecerTiempo( 99, 99, 99 ); // intenta hacer ajustes inválidos
  cout << "\n\nDespues de intentar ajustes invalidos:"
       << "\nTiempo universal: ";
  t.imprimirUniversal(); // 00:00:00
  cout << "\nTiempo estandar: ";
  t.imprimirEstandar(); // 12:00:00 AM
  cout << endl;

  return 0;
}
