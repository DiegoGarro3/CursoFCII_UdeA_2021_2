#ifndef SPIRAL_H
#define SPIRAL_H

#include <string> 
using namespace std;

//#include "../example1_clasebase2/empleadocomision.h"
#include "../CircularCProtot.h"

class Spiral : public Circular // NOTE: LOS ":" Y EL "PUBLIC" PARA INDICAR LA HERENCIA
{
 public:

  Spiral( double, double, double, double, double, double, double );
  ~Spiral();
  
  void setZpos( double, double); 
  vector <double> getZpos() const; 
  
  void imprimir(); 
  
 private:

  vector<double> zpos;
}; 
#endif
