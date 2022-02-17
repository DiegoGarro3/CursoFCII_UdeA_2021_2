#ifndef FECHA_H
#define FECHA_H
// definición de la clase Fecha

class Fecha
{
 public:
  Fecha( int = 1, int = 1, int = 2000 ); // constructor predeterminado
  void imprimir();
  
 private:
  int mes;
  int dia;
  int anio;
}; 

#endif


