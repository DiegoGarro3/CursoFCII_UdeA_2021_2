#include <cmath>
#include <iomanip>
#include<iostream>

#include "../Puntoa/ciruclar.h"


using namespace std;

class espiral : public circular {

    public: 

    espiral(double R,double w, double dt, double t, double phase, double Zo, double Vo);
    
    ~espiral();

    void setZo(double Zo);

    double getZo() const;

    void setVo(double Vo);

    double getVo() const;

    void Motion3d();
      
    private:
        double Z0;
        double V0;
};
