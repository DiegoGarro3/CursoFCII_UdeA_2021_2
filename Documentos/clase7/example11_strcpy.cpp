// Uso de strcpy y strncpy.
#include <iostream>
#include <cstring> // utilizar funciones de la biblioteca de manejo de cadenas

using namespace std;

int main()
{
  char x[] = "Feliz cumpleanios a ti"; // longitud de cadena: 22
  char y[ 25 ];
  char z[ 18 ];

  strcpy( y, x ); // copia el contenido de x en y
  cout << "La cadena en el arreglo x es: " << x
       << "\nLa cadena en el arreglo y es: " << y << '\n';

  // copia los primeros 17 caracteres de x a z
  strncpy( z, x, 17 ); // no copia el carácter nulo
  z[ 17 ] = '\0'; // adjunta '\0' al contenido de z
  cout << "La cadena en el arreglo z es: " << z << endl;
  
 return 0; 
}
