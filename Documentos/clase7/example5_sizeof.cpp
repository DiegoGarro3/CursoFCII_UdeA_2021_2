#include <iostream>
#include <iomanip>

using namespace std; 

size_t getSize( double * );

int main() 
{
  double arreglo[ 20 ]; // 20 valores double; ocupa 160 bytes en nuestro sistema
  cout << "El numero de bytes en el arreglo es " << sizeof( arreglo );
  cout << "\nEl numero de bytes devueltos por getSize es "
       << getSize( arreglo ) << endl;

  /*
  cout << endl;
  char c; // variable de tipo char
  int i; // variable de tipo int
  long l; // variable de tipo long
  float f; // variable de tipo float
  double d; // variable de tipo double
  long double ld; // variable de tipo long double
  int arreglo2[ 20 ]; // arreglo de int
  int *ptr2 = arreglo2;

  cout << "sizeof c = " << sizeof c
  << "\tsizeof(char) = " << sizeof( char )
  << "\nsizeof i = " << sizeof i
  << "\tsizeof(int) = " << sizeof( int )
  << "\nsizeof l = " << sizeof l
  << "\tsizeof(long) = " << sizeof( long )
  << "\nsizeof f = " << sizeof f
  << "\tsizeof(float) = " << sizeof( float )
  << "\nsizeof d = " << sizeof d
  << "\tsizeof(double) = " << sizeof( double )
  << "\nsizeof ld = " << sizeof ld
  << "\tsizeof(long double) = " << sizeof( long double )
  << "\nsizeof arreglo2 = " << sizeof arreglo2
  << "\nsizeof ptr = " << sizeof ptr2 << endl;

  cout << "\nnumber of elements = " << (sizeof arreglo2) / sizeof (int) << endl;
  */
  
  return 0; 
}

size_t getSize( double *ptr )
{
return sizeof( ptr );
}
