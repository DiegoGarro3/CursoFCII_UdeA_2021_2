#include<iostream>
#include<math.h>

using namespace std;

// Creamos las funciones

// La función de ejemplo, será dy/dx= y-x^2+1

double Funcion(double x, double y)
{
    double f = y-pow(x,2) +1; // Función de ejemplo
    return f;
}

// Buscamos la defición del método de Euler modificado (Wikipedia)

double Euler(float xf, float xi, float yi, float h) // definimos el mètodo
{
    while (fabs(xf-xi) > 0.0001) // Está será la presición (entre más alta, más se demora en ejecutar el programa)
    {
        double y_n= yi + h*Funcion(xi,yi); // creamos el paso siguiente, la cual evaluaremos en la y_n+1
        double yn = yi + h*(Funcion(xi,yi)+Funcion(xi+h,y_n))/2.0; // evaluamos para obtener la y_n+1
        xi += h; //actualizamos las condiciones iniciales, para x, dará un paso h
        yi = yn;// Traemos nuestra nueva condición inicial, pura recurrencia

    }
    
    return yi;
}
    
 // de manera analoga lo hacemos para el RK4 (otro wikipediazo)
 
 
 double RK4(float xf, float xi, float yi, float h)
{
    while (fabs(xf-xi) > 0.0001)
    {
        double k1 = Funcion(xi,yi); // definimos nuestras K del método (son 4 porque es RK 4 !)
        double k2 = Funcion(xi +0.5*h,yi + k1*h*0.5);
        double k3 = Funcion(xi +0.5*h,yi + k2*h*0.5);
        double k4 = Funcion(xi +h,yi + k3*h);
        double y_n= yi + h*(k1+2*k2+2*k3+k4)/6;
        xi += h; // actualizamos condiciones iniciales
        yi = y_n; // actualizamos condiciones iniciales 
    

    }
    
    return yi;
}
 
 
 //Creadas las funciones, pasamos a crear el main para comparar ambos métodos
 
int main()
{
    float xf=2; // Limite superior de la función
    float h=0.1; // corte de paso
    int lim = xf/h; // cantidad de pasos que vamos a dar 
    int i=1; // contador para imprimir valor a valor (en función del paso de corte)
    
    cout<<"La Ecuación Diferencial, resulta por ambos métodos, se muestra a continuación"<<endl;
    
    cout<<"x"<<"   "<<"Método de Euler"<<"   "<<"Método RK4"<<endl;

    while (i < lim+1)
    {
        cout << i*h <<"      "<< Euler(i*h,0,xf,h) <<"     "<< RK4(i*h,0,xf,h)<<endl;
        i++;
    }

	cout<< "Como era de esperarse, el método RK4 es más preciso"<<endl;



    return 0;
}
 


