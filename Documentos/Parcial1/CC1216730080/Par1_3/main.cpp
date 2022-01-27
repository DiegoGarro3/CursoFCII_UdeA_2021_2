
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


float RK4(float,float,float,float,float,int);
float mEm(float,float,float,float,float,int);

//Implementación de Runge-Kutta de orden 4.
float RK4(float (*funct)(float,float), float inf_lim,float sup_lim,float x0,float y0,int N){
    float h=(sup_lim-inf_lim)/N;
    float x=x0;
    float y=y0;
    cout<<setw(27)<<"Runge-Kutta 4th Order."<<endl;
    cout<<setw(11)<<"Iteration"<<setw(9)<<"x value"<<setw(9)<<"y value"<<endl;
    cout<<setw(7)<<"0"<<setw(10)<<x<<setw(12)<<y<<endl;
    for (int i=1;i<=N;i++){
        float k1=funct(x,y)*h;
        float k2=funct(x+h/2.0,y+k1/2.0)*h;
        float k3=funct(x+h/2.0,y+k2/2.0)*h;
        float k4=funct(x+h,y+k3)*h;
        
        x=x0+i*h;
        y+=(k1+2*k2+2*k3+k4)/6.0;
        cout<<setw(7)<<i<<setw(11)<<x<<setw(11)<<y<<endl;
    }
    return 0.0;
}

//Implementación de Modified Euler's Method.
float mEm(float (*funct)(float,float),float inf_lim,float sup_lim,float x0,float y0,int N){
    float h=(sup_lim-inf_lim)/N;
    float x=x0;
    float y=y0;
    cout<<setw(23)<<"Modified Euler."<<endl;
    cout<<setw(11)<<"Iteration"<<setw(9)<<"x value"<<setw(9)<<"y value"<<endl;
    cout<<setw(7)<<"0"<<setw(10)<<x<<setw(12)<<y<<endl;
    for(int i=1;i<=N;i++){
        float k1=funct(x,y)*h;
        float k2=funct(x+h,y+k1)*h;
        
        x=x0+i*h;
        y+=(k1+k2)/2.0;
        cout<<setw(7)<<i<<setw(11)<<x<<setw(11)<<y<<endl;
    }
    return 0.0;
};

//Para resolver dy/dx=f(x,y)=y-x**2+1, aquí se implementa la función f(x,y).
float funct(float _x,float _y){
    return _y-_x*_x+1;
}


int main()
{   
    //Conditions.
    float x_min=0.0;
    float x_max=2.0;
    float x0=0.0;
    float y0=0.5;
    
    // Número de iteraciones.
    int N_it=25;
    
    
    RK4(*(funct),x_min,x_max,x0,y0,N_it);
    mEm(*(funct),x_min,x_max,x0,y0,N_it);
}

