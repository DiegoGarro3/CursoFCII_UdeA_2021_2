/*
**********
Use las directivas del preprocesador #ifndef , #define y #endif
para formar una envoltura del preprocesador que evite incluir los 
archivos de encabezado más de una vez en un programa.
**********
*/
#ifndef TIEMPO_H
#define TIEMPO_H

class Tiempo
{
 public:
  Tiempo(); // constructor
  void establecerTiempo( int, int, int );
  std::string imprimirUniversal() const; 
  std::string imprimirEstandar() const; 
 private:
  unsigned int hora{0}; 
  unsigned int minuto{0};
  unsigned int segundo{0}; 
};

#endif
