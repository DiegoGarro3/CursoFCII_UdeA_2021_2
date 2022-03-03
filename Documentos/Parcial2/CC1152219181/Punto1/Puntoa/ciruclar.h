#include <cmath>
#include<iomanip>
#include<iostream>

class circular
{

public:
    circular(double R,double w, double dt, double t, double phase);
    ~circular();

    void setRadio(double R);
    double getRadio() const ;

    void setFrecuencia(double w);
    double getFrecuencia() const;

    void setIntervalo(double dt);
    double getIntervalo() const;

    void setTiempo(double t);
    double getTiempo() const;

    void setPhase(double phase);
    double getPhase() const;

    double Xpos(double time) const;
    double Ypos(double time) const;
    
    void Motion();

private:
    double radio;
    double omega;
    double Dt;
    double tiempo;
    double pha;

};

