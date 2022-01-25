#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


double f(double x,double y){
  return y-pow(x,2.0)+1;
  

}

double Euler(double x0,double y0,double h){
  return y0+h*f(x0,y0);


}

double EulerModified(double x0, double y0,double h){
  return y0+ 0.5*h*(f(x0,y0)+f(x0+h,Euler(x0,y0,h)));
  
}

double Rungekutta(double x0,double y0,double h){
  double k1{0};
  double k2{0};
  double k3{0};
  double k4{0};
  
  k1=f(x0,y0);
  k2=f(x0+h/2,y0+h*k1/2);
  k3=f(x0+h/2,y0+h*k2/2);
  k4=f(x0+h,y0+h*k3);
  

  return y0 + h*(k1+2*k2+2*k3+k4)/6;
   




}
  
