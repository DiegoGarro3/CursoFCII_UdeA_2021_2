#include <iostream>
#include "cursename.h"

using namespace std;

int main()
{
LibroCalificar miLibroCalificar( "CS101 Programacion en C++" );
miLibroCalificar.mostrarMensaje(); 
miLibroCalificar.RecibirCalificaciones(); 
return 0; 
}
