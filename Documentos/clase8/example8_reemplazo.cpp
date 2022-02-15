#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{

  string cadena1( "Los valores en cualquier subarbol izquierdo"
		  "\nson menos que el valor en el"
		  "\nnodo padre y los valores en"
		  "\ncualquier subarbol derecho son mayores"
		  "\nque el valor en el nodo padre" );
  cout << "Cadena original:\n" << cadena1 << endl << endl;

  // elimina todos los caracteres de (e incluyendo a) la ubicación 72 hasta el final de cadena1
  cadena1.erase( 72 );

  cout << "Cadena original despues de erase:\n" << cadena1 << "\n\nDespues del primer reemplazo:\n";
  
  int posicion = cadena1.find( " " ); // busca el primer espacio

  
  // reemplaza todos los espacios con un punto
  while ( posicion != string::npos )
    {
      cadena1.replace( posicion, 1, "." );
      posicion = cadena1.find( " ", posicion + 1 ); // se suma 1 a posicion para seguir buscando en la ubicación del siguiente carácter.
      //cout << "soy una tajada" << endl;
    }

  /*
    //NOTE1 : La función miembro find devuelve string::npos cuando no se encuentra el carácter de búsqueda

    //NOTE2: La función replace recibe tres argumentos: el subíndice del carácter en el objeto string en el que debe empezar 
    el reemplazo, el número de caracteres a reemplazar y la cadena de reemplazo.
  */
  
  cout << cadena1 << "\n\nDespues del segundo reemplazo:\n";
  
  posicion = cadena1.find( "." ); // busca el primer punto
  // reemplaza todos los puntos con dos signos de punto y coma
  // NOTA: esto sobrescribirá los caracteres
  
  while ( posicion != string::npos )
    {
      cadena1.replace( posicion, 2, "xxxxx;;yyy", 5, 2 );
      posicion = cadena1.find( ".", posicion + 1 );
    }
  
  cout << cadena1 << endl;
  
  return 0; 
}  
