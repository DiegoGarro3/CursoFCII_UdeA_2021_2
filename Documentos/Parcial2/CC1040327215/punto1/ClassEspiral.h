#ifndef ESPIRAL_H
#define ESPIRAL_H

#include <string> 
#include "ClassCircular.h"
using namespace std;

class Espiral : public Circular // hacemos la herencia con ":"
{
 private:
        double z0;
        double vz;
 public:

        Espiral( double, double, double, double, double, double, double);//constructor
        ~Espiral();// destructor
        
        void establecerz0(double); // establecemos la posición inicial en z
        double obtenerz0()const;
        
        void establecervz(double); // establecemos la velocidad en Z
        double obtenervz() const;
        
        vector<double>  zpos(); // nuestro vector de la posiciòn en Z de la partícula
};

#endif
