#include <iostream>
#include <cctype> // prototipos para islower y toupper

using namespace std; 

void convertirAMayusculas( char * );

void imprimirCaracteres( const char * ); // imprime usando apuntador a datos const

int main() 
{
  cout << "Apuntador no constante a datos no constantes" << endl;
  char frase[] = "caracTeres y $32.98";
  cout << "La frase antes de la conversion es: " << frase;
  convertirAMayusculas( frase );
  cout << "\nLa frase despues de la conversion es: " << frase << endl;
  cout<< endl;
  
  cout << "Apuntador no constante a datos constantes" << endl;
  const char frase2[] = "imprimir caracteres de una cadena";
  cout << "La cadena es:\n";
  imprimirCaracteres( frase2 ); 
  cout << endl;

  /*
  cout << "Apuntador constante a datos no constantes" << endl;
  int x, y;
  int  * const ptr = &x;  // el apuntador const se debe inicializar
  *ptr = 6;
  *ptr = &y;
  */
  //
  /*
  cout << "Apuntador constante a datos constantes" << endl;
  int z=3, w;
  const int  * const ptr2 = &z;
  cout << *ptr2 << endl;
  *ptr2 = 6;
  *ptr2 = &w;
  */

  return 0; 
}   

// convierte la cadena a letras mayúsculas
void convertirAMayusculas( char *sPtr )
{
  while ( *sPtr != '\0' ) 
    {
      if ( islower( *sPtr ) ) // si el caracter es minúscula,
	*sPtr = toupper( *sPtr ); // lo convierte a mayúscula
      sPtr++; // mueve sPtr al siguiente carácter en la cadena
    } 
}

// sPtr se puede modificar, pero no puede modificar el caracter al cual
// apunta; es decir, sPtr es un apuntador de "sólo lectura"
void imprimirCaracteres( const char *sPtr )
{
for ( ; *sPtr != '\0'; sPtr++ ) // no hay inicialización
  cout << *sPtr; // muestra el carácter sin modificación
}

