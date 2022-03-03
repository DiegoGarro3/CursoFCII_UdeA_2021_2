
#include<cmath>
#include<iomanip>
#include"xyz3D.h"
using namespace std;

Helicoidal::Helicoidal( double R, double frec, double d_t, double T,double alfa,double z_0, double v_z)
:Circular(R, frec, d_t, T, alfa)
{
    setz0(z_0);
    setVz(v_z);
};
Helicoidal::~Helicoidal()
{
    cout<<"Destructor objeto Helicoidal"<<endl;
};


void Helicoidal::setz0(double z)
{
    z0=z;
};
void Helicoidal::setVz(double vz)
{
    Vz=vz;
};
double Helicoidal::getz0()
{
    return z0;
};
double Helicoidal::getVz()
{
    return Vz;
};
vector<double> Helicoidal::zpos()
{
    int step=getTiempo()/getdeltaT();
    vector<double>Z(step+1,0);
    for(int k=0;k<step+1;k++)
    {
        Z[k]=z0+Vz*getdeltaT()*k;
    };
    return Z;
};