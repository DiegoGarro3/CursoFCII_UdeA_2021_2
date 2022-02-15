#include <iostream>
using namespace std; 

#include "destru.h" 
void crear( void );

CrearYDestruir primero( 1, "(global antes de main)" ); // objeto global

int main()
{
  cout << "\nFUNCION MAIN: EMPIEZA LA EJECUCION" << endl;
  CrearYDestruir segundo( 2, "(local automatico en main)" );
  
  static CrearYDestruir tercero( 3, "(local static en main)" );
  
  crear(); // llama a la función para crear objetos
  cout << "\nFUNCION MAIN: CONTINUA LA EJECUCION" << endl;
  //exit(1);
  
  CrearYDestruir cuarto( 4, "(local automatico en main)" );
  cout << "\nFUNCION MAIN: TERMINA LA EJECUCION" << endl;
  
  return 0;
}

void crear( void )
{
  cout << "\nFUNCION crear: EMPIEZA LA EJECUCION" << endl;
  CrearYDestruir quinto( 5, "(local automatico en crear)" );
  static CrearYDestruir sexto( 6, "(local static en crear)" );
  CrearYDestruir septimo( 7, "(local automatico en crear)" );
  cout << "\nFUNCION crear: TERMINA LA EJECUCION" << endl;
}
