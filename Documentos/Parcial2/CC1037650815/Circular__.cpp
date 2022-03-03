#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <ctime>
#include <math.h>
const float PI=3.1415;

#include "Circular_.h"

using namespace std;


//implemetacion de clase circular
Circular::Circular(double r, double w,double t, double fa,double dt)
{
  radio=r;
  frecuencia_angular=w;
  tiempo=t;
  fase=fa;
  n=t/dt;
  delta_t=dt;
  
  
}

void Circular::xpos()
{
  cout<<setw(15)<<"\n\nValores de X= ";
  for(int i =0; i<=n; i = i + 1)
    {
      cout<<(radio*cos(frecuencia_angular*i*delta_t+fase))<<" ";
    }

}


void Circular::ypos()
{
  cout<<setw(15)<<"\n\nValores de Y=";
  for(int i =0; i<=n; i = i + 1)
    {
      cout<<(radio*sin(frecuencia_angular*i*delta_t+fase))<<" ";
    }

}

Circular::~Circular()
{
}

//Implementación de clase expiral

Expiral::Expiral(double r, double w,double t, double fa, double dt, double vo, double poz)
{
  radio=r;
  frecuencia_angular=w;
  tiempo=t;
  fase=fa;
  n=t/dt;
  delta_t=dt;
  z0=vo;
  vz=poz;
}

void Expiral::zpos()
{
  cout<< setw(15)<<"\n\nValores de Z= ";
  for(int i =0; i<=n; i = i + 1)
    {
      cout<<(z0+vz*delta_t*i)<<" ";
    }
}

Expiral::~Expiral()
{
}

