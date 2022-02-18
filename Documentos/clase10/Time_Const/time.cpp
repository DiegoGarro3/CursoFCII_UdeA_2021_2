#include <iostream>
#include <iomanip>
#include "time.h"

using namespace std;

// función del constructor para inicializar los datos privados;
// llama a la función miembro setTiempo para establecer las variables;
// los valores predeterminados son 0 (vea la definición de la clase)
Tiempo::Tiempo( int hora, int minuto, int segundo )
{
setTiempo( hora, minuto, segundo );
}

void Tiempo::setTiempo( int hora, int minuto, int segundo )
{
setHora( hora );
setMinuto( minuto );
setSegundo( segundo );
}

void Tiempo::setHora( int h )
{
hora = ( h >= 0 && h < 24 ) ? h : 0; // valida la hora
}

void Tiempo::setMinuto( int m )
{
  minuto = ( m >= 0 && m < 60 ) ? m : 0; 
} 

void Tiempo::setSegundo( int s )
{
segundo = ( s >= 0 && s < 60 ) ? s : 0; 
} 

int Tiempo::getHora() const // las funciones obtener deben ser const
{
return hora;
} 

int Tiempo::getMinuto() const
{
return minuto;
} 

int Tiempo::getSegundo() const
{
return segundo;
}

// imprime el Tiempo en formato universal (HH:MM:SS)
void Tiempo::imprimirUniversal() const
{
cout << setfill( '0' ) << setw( 2 ) << hora << ":"
     << setw( 2 ) << minuto << ":" << setw( 2 ) << segundo  << "\n";
}


void Tiempo::imprimirEstandar() // observe que no hay declaración const
{
cout << ( ( hora == 0 || hora == 12 ) ? 12 : hora % 12 )
<< ":" << setfill( '0' ) << setw( 2 ) << minuto
<< ":" << setw( 2 ) << segundo << ( hora < 12 ? " AM" : " PM" );
}
