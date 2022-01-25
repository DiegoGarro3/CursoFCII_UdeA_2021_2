
#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

//function prototype for dy/dx=f(x,y)
double f(double, double); 

//Modified Euler's Method for differential equations
double Euler(float x, float x0, float y0, float h)
/* Arguments:
            x:  The value to caluculate y(x)
            x0: Initial value of x
            y0: Initial value of y
            h:  Step size
*/
{
    //stops when x0 is near x by an epsilon 0.000001 
    while (fabs(x-x0) > 0.000001)  
    {
        double y_a= y0 + h*f(x0,y0);
        double yn = y0 + h*(f(x0,y0)+f(x0+h,y_a))/2.0;
        x0 += h;
        y0 = yn;

    }
    
    return y0;
}


//Runge-Kutta Order Four Method for differential equations
double RK4(float x, float x0, float y0, float h)
/* Arguments:
            x:  The value to caluculate y(x)
            x0: Initial value of x
            y0: Initial value of y
            h:  Step size
*/

{   //stops when x0 is near x by an epsilon 0.000001
    while (fabs(x-x0) > 0.000001)
    {
        double k1 = f(x0,y0);
        double k2 = f(x0 +0.5*h,y0 + k1*h*0.5);
        double k3 = f(x0 +0.5*h,y0 + k2*h*0.5);
        double k4 = f(x0 +h,y0 + k3*h);
        double y_n= y0 + h*(k1+2*k2+2*k3+k4)/6;
        x0 += h;
        y0 = y_n;
    

    }
    
    return y0;
}



