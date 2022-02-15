#include <iostream>
#include "empleado.h"

using namespace std;

int main()
{
  // usa el nombre de la clase y el operador de resolución de ámbito binario
  // para acceder a la función numérica static getCuenta
  cout << "El numero de empleados antes de instanciar cualquier objeto es "
       << Empleado::getCuenta() << endl; // usa el nombre de la clase
 
  // usa new para crear en forma dinámica dos nuevos objetos Empleado
  // el operador new también llama al constructor del objeto
  Empleado *e1Ptr = new Empleado( "Kevin", "Cortes" );
  Empleado *e2Ptr = new Empleado( "Andrea", "Valencia" );
  
  // llama a getCuenta en el objeto Empleado nombre
  cout << "El numero de empleados despues de instanciar los objetos es "
       << (*e1Ptr).getCuenta();
  cout << "\n\nEmpleado 1: "
       << e1Ptr->getPrimerNombre() << " " << e1Ptr->getApellidoPaterno()
       << "\nEmpleado 2: "
       << e2Ptr->getPrimerNombre() << " " << e2Ptr->getApellidoPaterno() << "\n\n";

  
  delete e1Ptr;// desasigna la memoria
  e1Ptr = 0; // desconecta el apuntador del espacio de almacenamiento libre
  delete e2Ptr;
  e2Ptr = 0; 
  
  // no existen objetos, por lo que llama a la función miembro static getCuenta de nuevo
  // usando el nombre de la clase y el operador de resolución de ámbito binario
  cout << "El numero de empleados despues de eliminar los objetos es "
       << Empleado::getCuenta() << endl;
  
  return 0;
}
