#include"xy2D.h"
#include<iomanip>
#include<cmath>

Circular::Circular(double R, double omega,double DeltaT,double Time,double alfa)
{
    setradio(R);
    setfrecuencia(omega);
    setdeltaT(DeltaT);
    setTiempo(Time);
    setfase(alfa);
};

Circular::~Circular()
{
    cout<<"Destructor objeto circular"<<endl;
};

void Circular::setradio(double rad)
{
    radio=rad;
};

void Circular::setfrecuencia(double frec)
{
    frecuencia=frec;
};
void Circular::setdeltaT(double deltat)
{
    dt=deltat;
};
void Circular::setTiempo(double tiempo)
{
    time=tiempo;
};
void Circular::setfase(double alpha)
{
    phase=alpha;
};

double Circular::getradio()
{
    return radio;
};

double Circular::getfrecuencia()
{
    return frecuencia;
};
double Circular::getdeltaT()
{
    return dt;
};
double Circular::getTiempo()
{
    return time;
};
double Circular::getfase()
{
    return phase;
};

vector<double> Circular::xpos()
{
    int step=time/dt;
    vector<double>X(step+1,0);
    for(int k=0;k<step+1;k++)
    {
        X[k]=radio*cos(k*dt*frecuencia+phase);
    };
    return X;

};

vector<double> Circular::ypos()
{
    int step=time/dt;
    vector<double>Y(step+1,0);
    for(int k=0;k<step+1;k++)
    {
        Y[k]=radio*sin(k*dt*frecuencia+phase);
    };
    return Y;

};
vector<double> Circular::T()
{
    int step=time/dt;
    vector<double>T(step+1,0);
    for(int k=0;k<step+1;k++)
    {
        T[k]=k*dt;
    };
    return T;

};

