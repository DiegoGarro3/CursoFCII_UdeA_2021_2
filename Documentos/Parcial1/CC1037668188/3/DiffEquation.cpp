#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double f(double, double);    // Donde f es tal que:  y'=f(x,y)
double Euler_Modified(double,double,double);
double Runge_kutta4(double,double, double h);
double Exact_solution(double);

int main()
{
    double x0=0.0,y0(0.5),xf=2.0, h=0.2;
    double x_n=x0;
    double y_n_euler=y0;
    double y_n_rk4=y0;
    cout<<"Solucion de la ecuacion diff: y'=y-x^2+1, con y(0)=0.5, en el intervalo 0≤x≤2."<<endl;
    cout<<"Usando el metodo de euler modificado y el Runge kutta 4. con h=0.2."<<endl;
    cout<<"La solucion exacta de la ecuacion es y(x)=-0.5*exp(x)+(1+x)^2"<<endl;
    cout<<endl;
    cout<< "  x     Euler Mod.: y(x)      RK4: y(x)      Exact solution: y(x)    Error: Euler Mod.   Error:RK4 "<< endl;
    cout<< "----    ---------------      ----------      ----------------         ------------       ---------"<<endl;
    cout<<setprecision(2)<<x0<< setw(18)<<y0<< setw(18)<<y0<< setw(18)<<Exact_solution(x0)
    <<setw(20)<<0.0<<setw(20)<<0.0<<endl;

    for(x_n;x_n<2;x_n+=h)
    {
        if((x_n+h)>xf)
        break;
        y_n_euler=Euler_Modified(x_n,y_n_euler,h);
        y_n_rk4=Runge_kutta4(x_n,y_n_rk4,h);
        cout<<fixed<<setprecision(1)<<x_n+h<<setprecision(7)<<setw(18)<<y_n_euler
        << setw(18)<<y_n_rk4<< setw(18)<<Exact_solution(x_n+h)
        <<setw(23)<<abs(Exact_solution(x_n+h)-y_n_euler)<<setw(18)<<abs(Exact_solution(x_n+h)-y_n_rk4)<<endl;
    };
    return 0;
};

double f(double x, double y)
{
return y-pow(x,2.0)+1;
};
double Euler_Modified(double x, double y, double h)
{
    double sol;
    sol=y+h*(f(x,y)+f(x+h,y+h*f(x,y)))/2.0;

    return sol;
};

double Runge_kutta4(double x, double y, double h)
{
    
    double k1=h*f(x,y);
    double k2=h*f(x+h/2,y+k1/2);
    double k3=h*f(x+h/2,y+k2/2);
    double k4=h*f(x+h,y+k3);
    double sol=y+(k1+2*k2+2*k3+k4)/6;
    return sol;
};

double Exact_solution(double x)
{
    double sol=-0.5*exp(x)+pow(x+1,2.0);
    return sol;
}

