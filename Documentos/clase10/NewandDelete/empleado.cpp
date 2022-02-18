#include <iostream>
#include <cstring>

#include "empleado.h"

using namespace std;

// define e inicializa el miembro de datos static en alcance de archivo
int Empleado::cuenta = 0; // no puede incluir la palabra clave static

// define la función miembro static que devuelve el número de
// objetos Empleado instanciados (se declara static en Empleado.h)
int Empleado::getCuenta()
{
  return cuenta;
}

// el constructor asigna espacio en forma dinámica para nombre y apellido, y
// usa strcpy para copiar nombre y apellido en el objeto
Empleado::Empleado( const char * const nombre, const char * const apellido )
{
  primerNombre = new char[ strlen( nombre ) + 1 ]; // crea espacio
  strcpy( primerNombre, nombre ); // copia nombre en el objeto
  
  apellidoPaterno = new char[ strlen( apellido ) + 1 ]; // crea espacio
  strcpy( apellidoPaterno, apellido ); // copia apellido en el objeto
  
  cuenta++; // incrementa la cuenta static de empleados
  cout << "Se llamo al constructor de Empleado para " << primerNombre
       << ' ' << apellidoPaterno << "." << endl;
}

Empleado::~Empleado()
{
  cout << "Se llamo a ~Empleado() para " << primerNombre
       << ' ' << apellidoPaterno << endl;
  delete [] primerNombre; // libera la memoria
  delete [] apellidoPaterno; // libera la memoria
  cuenta--; // decrementa cuenta static de empleados
}

// devuelve el primer nombre del empleado
const char *Empleado::getPrimerNombre() const
{
  // const antes del tipo de retorno evita que el cliente modifique datos
  // private; el cliente debe copiar la cadena devuelta antes de que el
  // destructor elimine el almacenamiento para evitar un apuntador indefinido
  return primerNombre;
}

// devuelve el apellido paterno del empleado
const char *Empleado::getApellidoPaterno() const
{
  return apellidoPaterno;
}
