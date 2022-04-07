#include"path.h"
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;


Path_Integral::Path_Integral(int num_stepx, int num_stept,double t,double xi,double xf,double (*Pot)(double), double masa)
{
    M=num_stepx;
    N=num_stept;
    time=t;
    a=xi;
    b=xf;
    dx=(xf-xi)/M;
    dt=time/N;
    set_x();
    mass=masa;
    Vx=*Pot;
};

void Path_Integral::set_x()
{
    vector<double>S(M,0);
    for(int i=0;i<=M-1;i++)
    {
        S[i]=a+i*dx;
    };
    x=S;
};

vector<double> Path_Integral::get_x()
{
    return x;
};


int Path_Integral::pbc(int k)
{
    if(k==M)
    return 0;
    else if(k<0)
    return M-1;
    else
    return k;
};
vector<double> Path_Integral::camino(int step)
{
    vector<vector<double>>Result;

    vector<double>path(M,0);
    vector<double>prob(M,0);

    for(int j=0;j<=step;j++)
    {
        int k =1+rand()%(M-2);
        double change=2*dx*(((double) rand()/(RAND_MAX))-0.5);
        double Delta_E=mass*(pow(change,2)+2*change*path[pbc(k)]-change*(path[pbc(k+1)]+path[pbc(k-1)]))/dt+((*Vx)(path[k]+change)-(*Vx)(path[k]))*dt;
        if(Delta_E<=0)
        path[k]+=change;
        else if(exp(-Delta_E)>=((double) rand()/(RAND_MAX)))
        path[k]+=change;

        for(int l=0;l<=x.size()-1;l++)
        {
            if(x[l]<path[k] && path[k]<x[l+1])
            {
                prob[l]+=1;
            };
        };
    };
    
    return prob;
}

