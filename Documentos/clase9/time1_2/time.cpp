#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <sstream> // for ostringstream class
#include <string>
#include "time.h"

using namespace std;

Tiempo::Tiempo()
{
  hora = minuto = segundo = 0;
}

void Tiempo::establecerTiempo( int h, int m, int s )
{
  if ((h >= 0 && h < 24) && (m >= 0 && m < 60) && (s >= 0 && s < 60)) {
    hora = h;
    minuto = m;
    segundo = s;
  }
  else {
    throw invalid_argument(
			   "hora, minuto y/0 segundo estaban fuera de rango");
  }
} 

string Tiempo::imprimirUniversal() const
{
  ostringstream output;
  output << setfill( '0' ) << setw( 2 ) << hora << ":" 
       << setw( 2 ) << minuto << ":" << setw( 2 ) << segundo;
  
  return output.str();
} 

string Tiempo::imprimirEstandar() const
{
  ostringstream output;
  output << ( ( hora == 0 || hora == 12 ) ? 12 : hora % 12 ) << ":"
       << setfill( '0' ) << setw( 2 ) << minuto << ":" << setw( 2 )
       << segundo << ( hora < 12 ? " AM" : " PM" );

  return output.str();
}  
