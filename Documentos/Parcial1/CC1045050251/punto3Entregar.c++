// C++ code for solving the differential equation
// using Predictor-Corrector or Modified-Euler method
// with the given conditions, y(0) = 0.5, step size(h) = 0.2
// to find y(1)
// basado en
//geeksforgeeks.org/predictor-corrector-or-modified-euler-method-for-solving-differential-equation/
#include <bits/stdc++.h>
#include<iostream>
using namespace std;

// consider the differential equation
// for a given x and y, return v
double f(double x, double y) //declaracion de la ecuacion
{
	double v = y -  x * x + 1; //ecuacion a resolver
	return v;
}


// h es el paso
double predict(double x, double y, double h)/*esta funcion nos dara el valor siguiente
                                                con el  paso que
                                            continua en la grafica*/
{

	double y1p = y + h * f(x, y); //llamamos la funcion que queremos resolver y avanzamos un paso
	return y1p; //esto nos da el siguiente paso en la curva que esta resolviendo
}

// esta funcion corrige el metodo clasico de Euler
double correct(double x, double y,
			double x1, double y1,
			double h)
{
	// (x, y) are of previous step
	// and x1 is the increased x for next step
	// and y1 is predicted y for next step
	double e = 0.00001;
	double y1c = y1;

	do {
		y1 = y1c;
		y1c = y + 0.5 * h * (f(x, y) + f(x1, y1));
	} while (fabs(y1c - y1) > e);

	// every iteration is correcting the value
	// of y using average slope
	return y1c;
}

void printFinalValues(double x, double xn,
					double y, double h)
{

	while (x < xn) {
		double x1 = x + h; //hacemos correr la x desde 0 hasta 2 con pasos de 0.2
		double y1p = predict(x, y, h);
		double y1c = correct(x, y, x1, y1p, h); /*a medida que va corriendose la X se
                                              va haciendo la correccion  */
    x = x1;
		y = y1c;
	}

	cout << "El valor final de  Y en el intervalo 0<=x<=2 es=  "<< y <<"\n"<< endl; //imprimimos el valor final de Y
}

int main()
{
  //parte para el metodo Euler
	double x = 0, xn = 2, y = 0.5, h = 0.2; //condiciones iniciales x=0 y(0)=0.5, y la X termina en x=2
                                          // h es el tamaño del paso o sea un incremento delta

  cout<<"\n -----Resultado con el  metodo Euler------- \n";
  printFinalValues(x, xn, y, h);


  //parte que resuelve el Runge-Kutta

  float x0=0, y0=0.5, xnrunge=2, hrunge=0.2, yn, k1, k2, k3, k4, k;
  int i, n=10; //n es la cantidad de pasos(iteraciones)
               //que quiero que de antes de llegar al valor final
  for(i=0; i < n; i++){

    k1 = hrunge * (f(x0, y0));
    k2 = hrunge * (f((x0+hrunge/2), (y0+k1/2)));
    k3 = hrunge * (f((x0+hrunge/2), (y0+k2/2)));
    k4 = hrunge * (f((x0+hrunge), (y0+k3)));
    k = (k1+2*k2+2*k3+k4)/6;
    yn = y0 + k;
    x0 = x0+hrunge;
    y0 = yn;
    }
    cout<<"\n -----Resultado con el  metodo Runge-Kuta de orden 4------- \n";
    cout<<"\nEl valor final de Y en el intervalo 0<=X<=2  es \t"<<yn<<"\n";

    cout<<"\n -----Comparacion de metodos------ \n";
    cout<<"\n Con Runge-Kuta  \t"<<yn<<"\t"<<"con Euler \t"<< 5.694 <<"\t";
    cout<<"entonces hay una diferencia de \t"<<5.694-yn<<"\t entre metodo y metodo";
    cout<<"y como el metodo de Runge-Kuta de 4 orden se considera mejor entonces nos quedamos con Runge "<<yn<<"\n";

	return 0;


}
