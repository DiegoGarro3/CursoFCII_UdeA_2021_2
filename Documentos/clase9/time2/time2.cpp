#include <iostream>
#include <iomanip>

using namespace std;

#include "time2.h"

// el constructor de Tiempo inicializa cada miembro de datos con cero;
// asegura que los objetos Tiempo empiecen en un estado consistente
Tiempo::Tiempo( int hr, int min, int seg )
{
establecerTiempo( hr, min, seg ); 
}

void Tiempo::establecerTiempo( int h, int m, int s )
{
establecerHora( h ); // establece el campo private hora
establecerMinuto( m ); 
establecerSegundo( s ); 
}

void Tiempo::establecerHora( int h )
{
hora = ( h >= 0 && h < 24 ) ? h : 0;
}

// establece el valor de minuto
void Tiempo::establecerMinuto( int m )
{
minuto = ( m >= 0 && m < 60 ) ? m : 0; // valida el minuto
}

void Tiempo::establecerSegundo( int s )
{
segundo = ( s >= 0 && s < 60 ) ? s : 0; 
}

// devuelve el valor de la hora
int Tiempo::obtenerHora()
{
return hora;
}

int Tiempo::obtenerMinuto()
{
return minuto;
}

int Tiempo::obtenerSegundo()
{
return segundo;
}

void Tiempo::imprimirUniversal()
{
cout << setfill( '0' ) << setw( 2 ) << obtenerHora() << ":"
<< setw( 2 ) << obtenerMinuto() << ":" << setw( 2 ) << obtenerSegundo();
}

void Tiempo::imprimirEstandar()
{
cout << ( ( obtenerHora() == 0 || obtenerHora() == 12 ) ? 12 : obtenerHora() % 12 )
     << ":" << setfill( '0' ) << setw( 2 ) << obtenerMinuto() // NOTE: la llamada a obtenerMinuto()
<< ":" << setw( 2 ) << obtenerSegundo() << ( hora < 12 ? " AM" : " PM" );
}
