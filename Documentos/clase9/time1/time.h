/*
**********
Use las directivas del preprocesador #ifndef , #define y #endif
para formar una envoltura del preprocesador que evite incluir los 
archivos de encabezado más de una vez en un programa.
**********
*/
#ifndef TIEMPO_H
#define TIEMPO_H


// definición de la clase Tiempo
class Tiempo
{
 public:
  Tiempo(); // constructor
  void establecerTiempo( int, int, int );
  void imprimirUniversal(); // imprime la hora en formato universal
  void imprimirEstandar(); // imprime la hora en formato estándar
 private:
  int hora; // 0 - 23 (formato de reloj de 24 horas)
  int minuto; // 0 - 59
  int segundo; // 0 - 59
};

#endif
