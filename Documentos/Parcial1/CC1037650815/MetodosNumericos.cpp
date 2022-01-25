// C++ code for solving the differential equation
// using Predictor-Corrector or Modified-Euler method
// with the given conditions, y(0) = 0.5, step size(h) = 0.2
// to find y(1)
// basado en
//geeksforgeeks.org/predictor-corrector-or-modified-euler-method-for-solving-differential-equation/
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

double f(double x, double y) // para un x y un y retona v 
{
	double v = y -  x * x + 1; //Ecuación diferencial 
	return v;
}

double predict(double x, double y, double h)//Predice el sigte valor de (x.y) y el paso h
{
    double y1p = y + h * f(x, y); //el incremento + la función 
	return y1p; //esto nos da el siguiente paso en la curva que esta resolviendo
}

double correct(double x, double y, // Función corrige el método de Euler
			double x1, double y1,
			double h)
{
	// (x, y) paso previo
	// and x1 incremento de x para el próximo paso 
	// and y1 incremento de y
	double e = 0.00001;
	double y1c = y1;

	do {
		y1 = y1c;
		y1c = y + 0.5 * h * (f(x, y) + f(x1, y1));
	} while (fabs(y1c - y1) > e);

	
	return y1c;// En cada iteración se corrige el valor de la solución
}   

void printFinalValues(double x, double xn,
					double y, double h)
{

	while (x < xn) {
		double x1 = x + h; // intervalo en x de 0<=x<=2
		double y1p = predict(x, y, h);
		double y1c = correct(x, y, x1, y1p, h);
        x = x1;
		y = y1c;
	}
    cout<<"El valor de y en x = "<< x << " es:" << y << endl;
	cout << "El resultado obtenido por el método de Euler es:=  "<< y << endl; //Se imprime y
}

int main()
{
  //parte para el metodo Euler
	double x = 0, xn = 2, y = 0.5, h = 0.2; //condiciones iniciales 
  printFinalValues(x, xn, y, h);
  


  /*Método Runge-Kutta
  Calcula un y y lo imprime luego dentro de un for, cambia el valor inicial por el nuevo valor obtenido y se vuelve a calcular el siguiente
  */

  float x0=0, y0=0.5, xnkutta=2, hkutta=0.2, yn, k1, k2, k3, k4, k;
  int i, n=10; //Cantidad iteraciones
  for(i=0; i < n; i++){

    k1 = hkutta * (f(x0, y0));
    k2 = hkutta * (f((x0+hkutta/2), (y0+k1/2)));
    k3 = hkutta * (f((x0+hkutta/2), (y0+k2/2)));
    k4 = hkutta * (f((x0+hkutta), (y0+k3)));
    k = (k1+2*k2+2*k3+k4)/6;
    yn = y0 + k;
    x0 = x0+hkutta;
    y0 = yn;
    }
    
    cout<<"Valor de y en x = "<< xn<< " es " << yn<<endl;
    cout<<"El resultado obtenido por el método Runge Kutta es:"<<yn<<endl;
    



	return 0;


}
