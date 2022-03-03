#include <iostream>
#include <iomanip>
#include <math.h>
#include<string>

//DECLARACIÓN DE CLASE




using namespace std;

class Circular
{
protected:
  double radio;
  double frecuencia_angular;
  double delta_t;
  double tiempo;
  double n;
  double fase;
  
public:
  Circular(double =0,double =0, double  =0, double =0,double =0);
  void xpos();
  void ypos();
  ~Circular();
      
};

class Expiral: public Circular
{
protected:
  double z0;
  double vz;
public:
  Expiral(double =0,double =0, double  =0, double =0,double =0,double =0,double=0);
  void zpos();
  ~Expiral();
  
};

