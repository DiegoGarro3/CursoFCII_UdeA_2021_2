#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;


double Euler(float, float, float , float);
double RK4(float, float, float , float);

//Differential equation dy/dx = f(x,y)
double f(double x, double y)
{
    //double fun = (5*pow(x,2)-y)/(exp(x+y)); 
    double fun = y-pow(x,2) +1; //Define the desiered EDO
    return fun;
}

int main()
{   
    float xf=0;//x final
    float x0=0;//x initial
    float y0=0;//y initial

    cout << "Initial conditions" << endl;
    cout << "Enter x0: ";
    cin >> x0;
    //cout << endl;
    cout << "Enter y0: ";
    cin >> y0;
    //cout << endl;

    cout << "Enter x upper limit: ";
    cin >> xf;
    cout << "\n";

    float h=0.1;//step size (be careful if to change it)

    cout << "|" << setw(6) << fixed << "x" << "|" 
    << setw(15) << fixed << "Euler: y(x) " << "|"
    << setw(15) << fixed << "RK4: y(x)" << "|"
    << endl;
  
    cout << "----------------------------------------" 
    << endl;

    int u_lim = xf/h; //upper limit for the for cycle
    int l_lim = x0/h; //lower limit for the for cycle
    
    //Calculating y(x) over the desaired range of x 
    for (int i = l_lim ; i <= u_lim ;i++) 
    {
        cout << "|" << setw(6) << fixed << setprecision(1)<< i*h << "|" 
        << setw(15) << fixed << setprecision(6) << Euler(i*h,x0,y0,h) << "|"
        << setw(15) << fixed << setprecision(6) << RK4(i*h,x0,y0,h) << "|"
        << endl;
        
    }
    
    return 0;
}