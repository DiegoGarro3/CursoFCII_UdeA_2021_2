#include <iostream>
#include <iomanip>
using namespace std;

#include "vender.h"

Vendedor::Vendedor()
{
  for ( int i = 0; i < 12; i++ )
    ventas[ i ] = 0.0;
}

// obtiene 12 cifras de ventas del usuario mediante el teclado
void Vendedor::obtenerVentasDelUsuario()
{
  double cifraVentas;
  for ( int i = 1; i <= 12; i++ )
    {
      cout << "Escriba el monto de ventas para el mes " << i << ": ";
      cin >> cifraVentas;
      establecerVentas( i, cifraVentas );
    }

}

void Vendedor::establecerVentas( int mes, double monto )
{
  if ( mes >= 1 && mes <= 12 && monto > 0 )
    ventas[ mes - 1 ] = monto; // ajusta los subíndices de 0 a 11
  else // valor de mes o monto inválido
    cout << "Mes o cifra de ventas invalidos" << endl;
}

// imprime el total de ventas anuales (con la ayuda de la función utilitaria)
void Vendedor::imprimirVentasAnuales()
{
  cout << setprecision( 2 ) << fixed
       << "\nLas ventas anuales totales son: $"
       << totalVentasAnuales() << endl; // llama a la función utilitaria
} 

// función utilitaria privada para totalizar las ventas anuales
double Vendedor::totalVentasAnuales()
{
  double total = 0.0;
  
  for ( int i = 0; i < 12; i++ ) 
    total += ventas[ i ];
  
  return total;
}
