/*
Santiago Quintero Cordoba

Punto 3 parcial1

Observar que cuando k2=k3=k4=0 ambos metodos son parecidos con la diferencia de un
factor de 1/6 en uno de los elementos

En RK4 se obtiene una precision del orden de h^4 mientras que el metodo de Euler es del
orden de h, para la misma funcion al aumentar el valor de iteraciones ambos resultados 
tienden al mismo valor, por otro lado por la forma  cuando la funcion es contante ambos
metodos son el mismo.

Por la precision se hace mejor el empleo de RK4 pero a grandes particiones tenemos casi el mismo resultado
dando una mayor ventaja a RK4 ya que no necesita hacer tantos calculos a diferencia de Euler para 
aproximar la solucion
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//inicializacion de variables
double xf(0);//valor final de x
double x(0);//x
double yR(0);//y para el metodo RK4
double yE(0);//y para el metodo de Euler
int iteraciones(0);//iteraciones deseadas
double h(0);//Paso
/////////////////////

double funcion(double x_0,double y_0){//se da la funcion f(x,y) a la cual es equivalente dy/dx

    return pow(x_0,2) -2 * x_0 + 1;
}

double Euler(double h, double xi, double yi){//se implementa el metodo de Euler

    return yi + h*funcion(xi,yi);
}

double RK4(double h, double xi, double yi){//se implementa el metodode RK4
    
    double k1(0);
    double k2(0);
    double k3(0);
    double k4(0);

    k1=funcion(xi,yi);
    k2=funcion(xi + 0.5*h,yi+0.5*k1*h);
    k3=funcion(xi + 0.5*h,yi+0.5*k2*h);
    k4=funcion(xi + h,yi+k3*h);

    return yi + h*(k1 + 2*(k2 + k3) + k4)/6;
}

int main(){
    
    cout<<"Ingrese el valor inicial de x"<<endl;
    cin >>x;//se ingresa el valor inicial de x
    cout<<"Ingrese el valor incial de la funcion"<<endl;
    cin >> yE;//se ingresa el valor inicial de y
    yR=yE;
    cout<<"Hasta que valor de x quiere obtener y(x)"<<endl;
    cin >> xf;//se ingresa el valor final de x
    cout<<"Cuantas iteraciones quiere"<<endl;
    cin >> iteraciones;//se ingresa el numero de iteraciones queridad

    h=(xf-x)/iteraciones;//se calcula la particion h

    cout<<"\n";

    cout << "|" << setw(10) << "Iteracion"<< setw(10) << "x"<< setw(10) << "y(x)"<< setw(10) << "Metodo" << "|" <<endl;
    cout << "|" << setw(10) << "0" << setw(10) << setprecision(10) << x << setw(10) << fixed <<setprecision(3) <<yR << setw(10) << " "  << "|"  <<endl;
    
    for(int i=1;i<=iteraciones;i++){
        
        yE=Euler(h,x,yE);
        yR=RK4(h,x,yR);
        x+=h;
        cout << "|" << setw(10) << i << setw(10) <<fixed <<setprecision(3) << x << setw(10) << fixed <<setprecision(3) <<yR << setw(10) << "R-K 4" <<  "|"  <<endl;
        cout << "|" << setw(10) << i << setw(10) <<fixed << setprecision(3) <<x << setw(10) <<fixed <<setprecision(3) << yE << setw(10) << "Euler" <<"|"  <<endl;
    }

}