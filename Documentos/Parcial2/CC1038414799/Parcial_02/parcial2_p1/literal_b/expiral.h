#ifndef EXPIRAL_H
#define EXPIRAL_H

using namespace std;

#include "../literal_a/circular.h" //including base class 

//Inherit from Circular class 
class Expiral : public Circular { 

public:

    Expiral(double = 0.0, double=0.0, double =0.0, double =0.0, double=0.0, double =0.0, double=0.0);
    ~Expiral();

    //set functions
    void setZ0(double);
    void setVel_z(double);


    //get functions
    double getZ0() const;
    double getVel_z() const;

    void motion3D();

private:

    double z_ini;
    double z_vel;

};

#endif
