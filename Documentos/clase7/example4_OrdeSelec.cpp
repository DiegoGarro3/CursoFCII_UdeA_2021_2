#include <iostream>
#include <cctype> // prototipos para islower y toupper
#include <iomanip>

using namespace std; 

void ordenamientoSeleccion( int * const, const int );
void intercambiar( int * const, int * const );


int main() 
{
  const int tamanioArreglo = 10;
  int a[ tamanioArreglo ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

  cout << "Elementos de datos en el orden original\n";
  for ( int i = 0; i < tamanioArreglo; i++ ){
    cout << setw( 4 ) << a[ i ];
  }
  
  ordenamientoSeleccion( a, tamanioArreglo ); // ordena el arreglo

  cout << "\nElementos de datos en orden ascendente\n";
  for ( int j = 0; j < tamanioArreglo; j++ ){
    cout << setw( 4 ) << a[ j ];
  }
  
  cout << endl;
  
  return 0; 
}

void ordenamientoSeleccion( int * const arreglo, const int tamanio )
{
  int menor; 
  for ( int i = 0; i < tamanio - 1; i++ )
    {
      menor = i;
      // NOTE EL i+1 en el siguiente contador
      for ( int subindice = i + 1; subindice < tamanio; subindice++ ){
	if ( arreglo[ subindice ] < arreglo[ menor ] ){
	  menor = subindice;
	}
      }
      intercambiar( &arreglo[ i ], &arreglo[ menor ] ); 
    } 
}

void intercambiar( int * const elemento1Ptr, int * const elemento2Ptr )
{
  int contenido = *elemento1Ptr;
  *elemento1Ptr = *elemento2Ptr;
  *elemento2Ptr = contenido;
}

      
