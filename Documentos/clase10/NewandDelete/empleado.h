#ifndef EMPLEADO_H
#define EMPLEADO_H

class Empleado
{
 public:
  Empleado( const char * const, const char * const ); // constructor
  ~Empleado(); // destructor
  
  const char *getPrimerNombre() const; // devuelve el primer nombre
  const char *getApellidoPaterno() const; // devuelve el apellido paterno

  // función miembro static
  static int getCuenta(); // devuelve el número de objetos instanciados
  
 private:
  char *primerNombre;
  char *apellidoPaterno;
  // datos static
  static int cuenta; // número de objetos instanciados
};

#endif
