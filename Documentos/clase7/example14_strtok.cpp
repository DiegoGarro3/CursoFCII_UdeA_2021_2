// Uso de strcpy y strncpy.
#include <iostream>
#include <cstring> 

using namespace std;

int main()
{
  char enunciado[] = "Este es un enunciado con 7 tokens";
  char *tokenPtr;
  
  cout << "La cadena a dividir en tokens es:\n" << enunciado
       << "\n\nLos tokens son:\n\n";
  
  // empieza la division de enunciado en tokens
  tokenPtr = strtok( enunciado, " " );
  
  // continúa dividiendo enunciado en tokens hasta que tokenPtr se vuelve NULL
  while ( tokenPtr != NULL )
    {
      cout << tokenPtr << '\n';
      tokenPtr = strtok( NULL, " " ); // obtiene el siguiente token
    }
  
  cout << "\nDespues de strtok, enunciado = " << enunciado << endl;
  
  return 0; 
}
