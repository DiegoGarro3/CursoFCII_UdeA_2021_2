#include <string>
using namespace std; 

// Este ejemplo mecánico es sólo para fines pedagógicos (si no desean no lo tiene que escribir)
// la idea es que aprendamos cuando se llaman los contructores y los destructores

#ifndef CREAR_H
#define CREAR_H

class CrearYDestruir
{
 public:
  CrearYDestruir( int, string ); 
  ~CrearYDestruir(); // destructor
  
 private:
  int idObjeto; // número de ID para el objeto
  string mensaje; // mensaje que describe al objeto
};

#endif
