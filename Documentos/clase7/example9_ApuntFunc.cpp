#include <iostream>
#include <iomanip>

using namespace std; 

void ordenamientoSeleccion( int [], const int, bool (*)( int, int ) );
void intercambiar( int * const, int * const );
bool ascendente( int, int ); // implementa el orden ascendente
bool descendente( int, int ); // implementa el orden descendente
int main()
{
  const int tamanioArreglo = 10;
  int orden; // 1 = ascendente, 2 = descendente
  int contador; // subíndice del arreglo
  int a[ tamanioArreglo ] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };
  cout << "Escriba 1 para orden ascendente,\n"
       << "Escriba 2 para orden descendente: ";
  cin >> orden;
  cout << "\nElementos de datos en el orden original\n";

  // imprime el arreglo original
  for ( contador = 0; contador < tamanioArreglo; contador++ )
    cout << setw( 4 ) << a[ contador ];

  // ordena el arreglo en forma ascendente; pasa la función ascendente
  // como un argumento para especificar el orden ascendente
  if ( orden == 1 )
    {
      ordenamientoSeleccion( a, tamanioArreglo, ascendente );
      cout << "\nElementos de datos en orden ascendente\n";
    }
  
  // ordena el arreglo en forma descendente; pasa la función descendente
  // como argumento para especificar el orden en forma descendente
  else
    {
      ordenamientoSeleccion( a, tamanioArreglo, descendente );
      cout << "\nElementos de datos en orden descendente\n";
    } 
  
  // imprime el arreglo ordenado
  for ( contador = 0; contador < tamanioArreglo; contador++ )
    cout << setw( 4 ) << a[ contador ];
  
  cout << endl;
  return 0; // indica que terminó correctamente
} 

void ordenamientoSeleccion( int trabajo[], const int tamanio, bool (*compara)( int, int ) )
{
  int menorOMayor; 
  for ( int i = 0; i < tamanio - 1; i++ )
    {
      menorOMayor = i; 
      // itera para encontrar el índice del elemento más pequeño (o más grande)
      for ( int index = i + 1; index < tamanio; index++ )
	if ( !(*compara)( trabajo[ menorOMayor ], trabajo[ index ] ) )
	  menorOMayor = index;
      intercambiar( &trabajo[ menorOMayor ], &trabajo[ i ] );
    } 
}

void intercambiar( int * const elemento1Ptr, int * const elemento2Ptr )
{
  int contenido = *elemento1Ptr;
  *elemento1Ptr = *elemento2Ptr;
  *elemento2Ptr = contenido;
}

bool ascendente( int a, int b )
{
return a < b; // devuelve true si a es menor que b
}

bool descendente( int a, int b )
{
return a > b; 
}
