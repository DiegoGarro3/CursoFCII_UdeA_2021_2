#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <functional>

#include "DifEqSolver.h"

using namespace std;

// el constructor inicializa las variables privadas
//DifEqSolver::DifEqSolver( string nombre, const double x0, const double y0 const int step )
DifEqSolver::DifEqSolver(const std::function<double(double, double)> foo)
{
 double initialx=0, initialy=0, step=0, finalx=0; 
 //#define f(x,y) (2*x)
 f=foo;
 cout << "Introdusca el valor inicial de x (ej 0)" << endl;
 cin >> initialx;
 x0=initialx;
 cout << "Introdusca el valor inicial de y (ej 0.5)" << endl;
 cin >> initialy;
 y0=initialy;
 cout << "Introdusca el paso h (ej 0.1)" << endl;
 cin >> step;
 h=step;
 cout << "Introdusca el x final (ej 2)" << endl;
 cin >> finalx;
 xf=finalx;
 
}

double DifEqSolver::ModifiedEuler()
{  
  double K1=0,K2=0,ynext=0;
  //double size= (xf-x0)/h
  //long double yarray[size]
  K1=h*f(x0,y0);
  K2=h*f((x0+h),(y0+K1));
  ynext=y0+(K1+K2)/2;
  //yarray[i]=ynext;
  return ynext;
}

double DifEqSolver::RungeKutta4o(double y0r)
{  
  double K1=0,K2=0,K3=0,K4=0,ynex=0;
  K1 = h*(f(x0, y0r));
  K2 = h*(f((x0+h/2),(y0r+K1/2)));
  K3 = h*(f((x0+h/2),(y0r+K2/2)));
  K4 = h*(f((x0+h),(y0r+K3)));
  ynex = y0r + (K1+2*K2+2*K3+K4)/6;
  return ynex;
}

void DifEqSolver::integrationcomparison()
{ 
  double ynME=0,ynRK=0;
  double y0rk=y0; //y inicial para el runge kutta
  double size= (xf-x0)/h; //numero de pasos
  double Metdif=0;
  cout << setw(14) << "Modified Euler" << setw(30) << "Runge Kutta 4th Order" << setw(30) << "Method difference" << endl;
  cout << setw(14) << fixed << setprecision(10) << y0 << setw(30) << y0rk << setw(30) << Metdif << endl;
  for(int i=0; i<size; i += 1){
    
    ynME=ModifiedEuler();
    y0=ynME;

    ynRK=RungeKutta4o(y0rk);
    y0rk=ynRK;
    x0=x0+h;
 
    Metdif=(ynRK-ynME);
    cout << setw(14) << setprecision(10) << y0 << setw(30) << y0rk << setw(30) << Metdif << endl;
  }
  cout <<"El metodo de Euler difiere del metodo de orden 4 de Runge-Rutta, esta diferencia aumenta con cada paso o iteracion, aumentando el error en la solución" << endl; 
}

