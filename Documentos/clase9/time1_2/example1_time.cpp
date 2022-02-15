#include <iostream>
#include <stdexcept>
#include "time.h"

using namespace std;

void displayTime(const string& message, const Tiempo& time) {
cout << message << "\nformato Universal: " << time.imprimirUniversal()
<< "\nFormato Standard: " << time.imprimirEstandar() << "\n\n";
}

int main(){
  
  Tiempo t;

  displayTime("El tiempo inicial es ", t);
  
  t.establecerTiempo( 13, 27, 6 ); 
  displayTime("despues de setear el tiempo:", t);

  try {
    t.establecerTiempo(99, 99, 99); // todos los valores fuera de rango
  }
  catch (invalid_argument& e) {
    cout << "Exception: " << e.what() << "\n\n";
  }

  return 0;
}
