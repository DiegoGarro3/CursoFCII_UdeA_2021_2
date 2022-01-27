#include <iostream>
#include <iomanip>

using namespace std; 

void copia1( char *, const char * ); // segundo argumento: un apuntador a una constante tipo carácter; es decir, una cadena constante
void copia2( char *, const char * );

int main() 
{
  char cadena1[ 10 ];
  char *cadena2 = "Hola";
  char cadena3[ 10 ];
  char cadena4[] = "Hasta luego";
  
  copia1( cadena1, cadena2 ); // copia cadena2 a cadena1
  cout << "cadena1 = " << cadena1 << endl;
  
  copia2( cadena3, cadena4 ); // copia cadena4 a cadena3
  cout << "cadena3 = " << cadena3 << endl;
  
  return 0; 
}

// copia s2 a s1 usando notación de arreglos
void copia1( char * s1, const char * s2 )
{
  // la copia ocurre en el encabezado del for
  for ( int i = 0; ( s1[ i ] = s2[ i ] ) != '\0'; i++ )
    ; // no hace nada en el cuerpo
} 

// copia s2 a s1 usando notación de apuntador
void copia2( char *s1, const char *s2 )
{
  for ( ; ( *s1 = *s2 ) != '\0'; s1++, s2++ )// como s1 y s2 cambian en cada brico del ciclo
    ; 

}
//El primer argumento para copia1 y copia2 debe ser un arreglo lo bastante grande como para contener la cadena en el segundo argumento
