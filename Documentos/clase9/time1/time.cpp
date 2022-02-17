#include <iostream>
#include <iomanip>
#include "time.h"
#include <stdexcept>

using namespace std;

Tiempo::Tiempo()
{
  hora = minuto = segundo = 0;
}

void Tiempo::establecerTiempo( int h, int m, int s )
{
  hora = ( h >= 0 && h < 24 ) ? h : 0; // valida la hora
  minuto = ( m >= 0 && m < 60 ) ? m : 0; // valida el minuto
  segundo = ( s >= 0 && s < 60 ) ? s : 0; // valida el segundo
} 

// imprime el Tiempo en formato de hora universal (HH:MM:SS)
void Tiempo::imprimirUniversal()
{
  cout << setfill( '0' ) << setw( 2 ) << hora << ":" // NOTE: el setfill('0'). Ya le es familiar
       << setw( 2 ) << minuto << ":" << setw( 2 ) << segundo;
} 

// imprime el Tiempo en formato de hora estándar (HH:MM:SS AM or PM)
void Tiempo::imprimirEstandar()
{
  cout << ( ( hora == 0 || hora == 12 ) ? 12 : hora % 12 ) << ":"
       << setfill( '0' ) << setw( 2 ) << minuto << ":" << setw( 2 )
       << segundo << ( hora < 12 ? " AM" : " PM" );
}  
