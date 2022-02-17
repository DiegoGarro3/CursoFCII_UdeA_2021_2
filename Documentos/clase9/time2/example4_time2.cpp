#include <iostream> 
using namespace std;

#include "time2.h"

int main()
{
  Tiempo t1;// valor predeterminado en todos los argumentos
  Tiempo t2(2 ); // se especifica hora; valores predeterminados para minuto y segundo
  Tiempo t3(21, 34 ); 
  Tiempo t4(12, 25, 42 ); 
  Tiempo t5(27, 74, 99 ); // se especifican valores incorrectos
  
  cout << "Se construyo con:\n\nt1: todos los argumentos predeterminados\n";
  t1.imprimirUniversal(); // 00:00:00
  cout  << "\n ";
  t1.imprimirEstandar(); // 12:00:00 AM

  cout << "\n\nt2: se especifico hora; minuto y segundo predeterminados\n";
  t2.imprimirUniversal(); // 02:00:00
  cout << "\n ";
  t2.imprimirEstandar(); // 2:00:00 AM
  
  cout << "\n\nt3: se especificaron hora y minuto; segundo predeterminado\n";
  t3.imprimirUniversal(); // 21:34:00
  cout << "\n ";
  t3.imprimirEstandar(); // 9:34:00 PM
  
  cout << "\n\nt4: se especificaron hora, minuto y segundo\n";
  t4.imprimirUniversal(); // 12:25:42
  cout << "\n ";
  t4.imprimirEstandar(); // 12:25:42 PM

  cout << "\n\nt5: se especificaron valores invalidos\n";
  t5.imprimirUniversal(); // 00:00:00
  cout << "\n ";
  t5.imprimirEstandar(); // 12:00:00 AM
  cout << endl;
  
  return 0;
}


