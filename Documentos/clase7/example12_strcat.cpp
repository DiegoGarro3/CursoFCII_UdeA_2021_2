// Uso de strcpy y strncpy.
#include <iostream>
#include <cstring> // utilizar funciones de la biblioteca de manejo de cadenas

using namespace std;

int main()
{
  char s1[ 20 ] = "Feliz "; // longitud: 6
  char s2[] = "Anio Nuevo "; // longitud: 11
  char s3[ 40 ] = "";
  
  cout << "s1 = " << s1 << "\ns2 = " << s2;
  strcat( s1, s2 ); // concatena s2 con s1 (longitud: 17)
  
  cout << "\n\nDespues de strcat(s1, s2):\ns1 = " << s1 << "\ns2 = " << s2;
  
  // concatena los primeros 6 caracteres de s1 con s3
  strncat( s3, s1, 6 ); // coloca '\0' despues del ultimo caracter
  cout << "\n\nDespues de strncat(s3, s1, 6):\ns1 = " << s1
       << "\ns3 = " << s3;
  
  strcat( s3, s1 ); // concatena s1 con s3
  cout << "\n\nDespues de strcat(s3, s1):\ns1 = " << s1<< "\ns3 = " << s3 << endl;
  
  
 return 0; 
}
