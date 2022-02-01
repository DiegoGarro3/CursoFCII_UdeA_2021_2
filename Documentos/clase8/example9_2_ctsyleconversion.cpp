#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  string cadena1( "CADENAS" ); // constructor de string con char* arg
  int longitud = cadena1.length();
  //char ptr2[longitud + 1]; // incluyendo el carácter nulo
  char* ptr2{new char[longitud + 1]}; // incluyendo el carácter nulo

  // copia caracteres de cadena1 a la memoria asignada
  cadena1.copy( ptr2, longitud, 0 ); // copia cadena1 a ptr2 char*
  ptr2[ longitud ] = '\0'; // agrega el terminador nulo
  cout << "el objeto string cadena1 es " << cadena1
       << "\ncadena1 convertida a una cadena estilo C es "
       << cadena1.c_str() << endl;

  //const char* ptr1{nullptr};
  //ptr1= cadena1.c_str(); // apuntador const char *(incluyendo el carácter nulo)
  //cout << "\nptr1 es " << ptr1 << endl;


  cout << "\nptr2 es " << ptr2 << endl;
  cout << endl;

  cout << "ahora en notacion de apuntadores" << endl;

  // imprime cada carácter usando un apuntador
  for ( int i = 0; i < longitud; i++ )
    cout << *( ptr2 + i ); // usa aritmética de apuntadores

  cout << endl;
  
  return 0; 
}  
