#include <iostream>
#include <cstring> 

using namespace std;

int main()
{
  const char *cadena1 = "abcdefghijklmnopqrstuvwxyz";
  const char *cadena2 = "cuatro";
  const char *cadena3 = "Jazz"; // Jazz le gano a Suns, ¿Como la ven?.

  cout << "La longitud de\"" << cadena1 << "\" es " << strlen( cadena1 )
       << "\nLa longitud de\"" << cadena2 << "\" es " << strlen( cadena2 )
       << "\nLa longitud de\"" << cadena3 << "\" es " << strlen( cadena3 )
       << endl;
  
 return 0; 
}
