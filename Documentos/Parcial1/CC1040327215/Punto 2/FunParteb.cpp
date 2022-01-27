#include <iostream>
#include <iomanip> 
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "ClassParteb.h"

using namespace std;


int main() //funcion principal
{
  Craps JuegoCraps; //crea objeto de la clase Craps
  JuegoCraps.Menu();  //llama menu para comenzar
  
  return 0;
}
