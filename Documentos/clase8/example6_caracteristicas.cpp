#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void imprimirEstadisticas( const string & );

int main()
{
  string cadena1;
  
  cout << "Estadísticas antes de la entrada:\n" << boolalpha;
  imprimirEstadisticas( cadena1 );
  
  // solo se lee "sopita" de "sopita caliente"
  cout << "\n\nEscriba una cadena: ";
  cin >> cadena1; 
  cout << "La cadena introducida fue: " << cadena1;
  
  cout << "\nEstadisticas despues de la entrada:\n";
  imprimirEstadisticas( cadena1 );

  // lee "caliente"
  cin >> cadena1; // delimitada por espacio en blanco
  cout << "\n\nEl resto de la cadena es: " << cadena1 << endl;
  imprimirEstadisticas( cadena1 );

  // adjunta 46 caracteres a cadena1
  cadena1 += "1234567890abcdefghijklmnopqrstuvwxyz1234567890";
  cout << "\n\ncadena1 es ahora: " << cadena1 << endl;
  imprimirEstadisticas( cadena1 );

  // agrega 10 elementos a cadena1
  cadena1.resize( cadena1.length() + 10 );
  cout << "\n\nEstadisticas despues de cambiar el tamanio en base a (length + 10):\n";
  imprimirEstadisticas( cadena1 );
  
  cout << endl;
  
 return 0; 
}  
 
// muestra las estadísticas de la cadena
void imprimirEstadisticas( const string &refString )
{
  cout << "capacidad: " << refString.capacity() << "\ntamanio max: "
       << refString.max_size() << "\ntamanio: " << refString.size()
       << "\nlongitud: " << refString.length()
       << "\nvacia: " << refString.empty();
}
