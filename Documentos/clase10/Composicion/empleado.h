#include "fecha.h" // incluye la definición de la clase Fecha

class Empleado
{
 public:
  Empleado( const char * const, const char * const,
	    const Fecha &, const Fecha & );
  void imprimir() const;
  ~Empleado(); // se proporciona para confirmar el orden de destrucción
  
 private:
  char primerNombre[ 25 ];
  char apellidoPaterno[ 25 ];
  const Fecha fechaNacimiento; // composición: objeto miembro
  const Fecha fechaContratacion; // composición: objeto miembro
};
