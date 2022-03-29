#include"hiperbolica.h"
#include<iostream>
#include<cmath>

using namespace std;

//prototipos de f(x) y g(x)
double fx(double);
double gx(double);
double rhox(double,double);

int main()
{   //parametros
    double alfa=2.0;
    double l=1.0;
    double time=1.0;
    double dt=0.05;
    double u_x0l=0;
    int par=10;  //partiones del interval[0,1]
    Hiperbolica Onda(alfa,l,time,dt,par,u_x0l,u_x0l,fx,gx,rhox);
    vector<vector<float>>W_ij=Onda.solucion();
    W_ij=Onda.solucion();
    cout<< "X_i             u(X_i,t_20) " << endl;
    cout<< "----------        ------------      "<<endl;

    for(int i=0;i<=par;i++)
    {
    cout<<left<<setw(15)<<i*(l/par)<<setw(15)<<W_ij[20][i]<<endl;
    };
    return 0;
};

double fx(double s)
{
    return sin(M_PI*s);
};

double gx(double s)
{
    return 0.0;
};
double rhox(double xx,double tt)
{
    return 0.0;
};