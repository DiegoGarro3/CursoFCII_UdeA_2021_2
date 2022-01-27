#include <iostream>
#include <iomanip>
#include <cstdlib> 
#include <ctime>
using namespace std;

#include "cartas.h"

MazoDeCartas::MazoDeCartas()
{
  for ( int fila = 0; fila <= 3; fila++ )
    {
      for ( int columna = 0; columna <= 12; columna++ )
	{
	  mazo[ fila ][ columna ] = 0; 
	}
    } 
  srand( time( 0 ) ); 
}

void MazoDeCartas::barajar()
{
  int fila; 
  int columna; 
  // para cada una de las 52 cartas, selecciona una posición del mazo al azar
  for ( int carta = 1; carta <= 52; carta++ )
    {
      do 
	{
	  fila = rand() % 4; // selecciona al azar la fila (0 a 3)
	  columna = rand() % 13; // selecciona al azar la columna (0 a 12)
	} while( mazo[ fila ][ columna ] != 0 );
      
      
      mazo[ fila ][ columna ] = carta;
    } 
}

void MazoDeCartas::repartir()
{
  // inicializa el arreglo palo
  static const char *palo[ 4 ] =
    { "Corazones", "Diamantes", "Bastos", "Espadas" };
  // inicializa el arreglo cara
  static const char *cara[ 13 ] =
    { "As", "Dos", "Tres", "Cuatro", "Cinco", "Seis", "Siete",
      "Ocho", "Nueve", "Diez", "Sota", "Reina", "Rey" };

  for ( int carta = 1; carta <= 52; carta++ )
    {
      for ( int fila = 0; fila <= 3; fila++ )
	{
	  // itera a través de las columnas del mazo para la fila actual
	  for ( int columna = 0; columna <= 12; columna++ )
	    {
	      // si la posición contiene la carta actual, la muestra
	      if ( mazo[ fila ][ columna ] == carta )
		{
		  cout << setw( 5 ) << right << cara[ columna ]
		       << " de " << setw( 8 ) << left << palo[ fila ]
		       << ( carta % 2 == 0 ? '\n' : '\t' );
		}
	    } //
	} // fin
    } // fin de
}
