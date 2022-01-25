#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;


double f(double x,double y);

double Euler(double x0,double y0,double h);

double EulerModified(double x0, double y0,double h);

double Rungekutta(double x0,double y0,double h);
  

int main(){
  double h=2.0/10.0; // Division del intervalo (0,2)
  double yn=0.5; //Condiciones iniciales
  double yrk=0.5;
  double x=0.0;

  std::cout << setw(8) << fixed << "x" << setw(20) << fixed << "EulerModified" << setw(20) << fixed << "RungeKutta"<< setw(20) << fixed << "Delta"<< std::endl;
  std::cout << setw(8) << fixed << "---" << setw(20) << fixed << "-------------"<< setw(20) << fixed << "----------"<<  setw(20) << fixed << "------"<<std::endl;
  std::cout  << setw(8) << fixed << 0.0 << setw(20) << fixed << yn  << setw(20) << fixed << yn <<  setw(20) << fixed <<  0  << std::endl;

  
  while(x<=2){

    yn=EulerModified(x,yn,h); //Redefinicion de los yn para calcular el yn+1 de la recurrencia
    yrk=Rungekutta(x,yrk,h);
    x+=h;
    //Condicion para solo calcular hasta x=2.0
    if (x>2){
      break;

    }

     std::cout  << setw(8) << fixed << x << setw(20) << fixed << yn << setw(20) << yrk <<  setw(20) << fixed <<  abs(yn-yrk) << std::endl;

      
    
    

    
 

    
    
   

  }
  
  
  

  return 0;
}
