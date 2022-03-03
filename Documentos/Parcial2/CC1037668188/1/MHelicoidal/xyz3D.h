#ifndef MOVIMIENTO3D_H
#define MOVIMIENTO3D_H
#include"../MCircular/xy2D.h"
#include<iostream>
#include<vector>

using namespace std;

class Helicoidal: public Circular 
{
    public:
    Helicoidal(double,double,double,double,double,double,double);
    ~Helicoidal();
    double getz0(void);
    void setz0(double);
    double getVz(void);
    void setVz(double);
    vector<double> zpos();

    private:
    double z0;
    double Vz;

    

};

#endif