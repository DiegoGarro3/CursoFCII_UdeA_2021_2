
#include <iostream>
//using namespace std; 

#include "destru.h"

CrearYDestruir::CrearYDestruir( int ID, string cadenaMensaje )
{
  idObjeto = ID; // establece el número de ID del objeto
  mensaje = cadenaMensaje; // establece el mensaje descriptivo del objeto
  cout << "El constructor del objeto " << idObjeto << "se ejecuta"<< mensaje << endl;
}

CrearYDestruir::~CrearYDestruir()
{
// imprime nueva línea para ciertos objetos; mejora la legibilidad
cout << ( idObjeto == 1 || idObjeto == 6 ? "\n" : "" );
cout << "El destructor del objeto " << idObjeto << "se ejecuta"<< mensaje << endl;
}
