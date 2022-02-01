#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  string cadena1( "mediodia es 12 pm; medianoche no es." );
  int ubicacion;
  
  // encuentra "es" en las ubicaciones 9 y 33
  cout << "Cadena original:\n" << cadena1
       << "\n\n(find) \"es\" se encontro en: " << cadena1.find( "es" )
       << "\n(rfind) \"es\" se encontro en: " << cadena1.rfind( "es" );

  //NOTE: RFIND busca de drecha a izquierda. it is in reverse (rfind)
  
  // encuentra 'e' en la ubicación 1
  ubicacion = cadena1.find_first_of( "liesop" );
  cout << "\n\n(find_first_of) encontro '" << cadena1[ ubicacion ]
       << "’ del grupo \"liesop\" en: " << ubicacion;

  // NOTE: "find_first_of" para localizar la primera ocurrencia en cadena1 de cualquier carácter en "liesop"

  // encuentra 's' en la ubicación 34
  ubicacion = cadena1.find_last_of( "liesop" );
  cout << "\n\n(find_last_of) encontro '" << cadena1[ ubicacion ]
       << "’ del grupo \"liesop\" en: " << ubicacion;

  //NOTE: find_last_of para buscar la última ocurrencia en cadena1 de cualquier carácter en "liesop" .
  
  // encuentra '1' en la ubicación 12
  ubicacion = cadena1.find_first_not_of( "medop ias" );
  cout << "\n\n(find_first_not_of) '" << cadena1[ ubicacion ]
       << "’ no esta contenido en \"medop ias\" y se encontro en: "
       << ubicacion;

  //NOTE: find_first_not_of para buscar el primer carácter que no esté contenido en "medop ias"
  

  // encuentra ';' en la ubicación 17
  ubicacion = cadena1.find_first_not_of( "12medop ias" );
  cout << "\n\n(find_first_not_of) '" << cadena1[ ubicacion ]
       << "’ no esta contenido en \"12medop ias\" y se "
       << "encontro en: " << ubicacion << endl;

  
  // busca los caracteres que no estén en cadena1
  ubicacion = cadena1.find_first_not_of("mediodia es 12 pm; medianoche no es." );
  cout << "\nfind_first_not_of(\"mediodia es 12 pm; medianoche no es.\")"
       << " devuelve: " << ubicacion << endl;
  
  
return 0; 
}  
