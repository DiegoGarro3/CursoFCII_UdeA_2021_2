#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <math.h>
#include <fstream> // flujo de archivo
#include <sstream> 

using namespace std;

#include "FiniteDifEqSol.h"

// y''(x)=p(x)*y'+q(x)*y+r(x)


//for the dif equation: y''= 4*y - 4*x, boundary conditions: x0=0,xf=1,y0=0,yf=2
const double pf(double x) {
    return 0; //(-2/x);
}
const double qf(double x) {
    return 4;//-1; //(2/pow(x,2));
}
const double rf(double x) {
    return -4*x;//0; //(sin(log(x))/pow(x,2));
}


//for the wave equation, boundary conditions: x0=5,xf=30,y0=1,yf=1
const double pfw(double x) {
    return 0; //(-2/x);
}
const double qfw(double x) {
    return -1; //(2/pow(x,2));
}
const double rfw(double x) {
    return 0; //(sin(log(x))/pow(x,2));
}


//for the book example dif eq: y''=(-2/x)*y' + (2/pow(x,2))*y + sin(log(x))/pow(x,2) , boundary conditions: x0=0,xf=1,y0=0,yf=2
const double pfe(double x) {
    return (-2/x);
}
const double qfe(double x) {
    return (2/pow(x,2));
}
const double rfe(double x) {
    return (sin(log(x))/pow(x,2));
}

double analiticsol (double x){
   return exp(2)*(1/(exp(4)-1))*(exp(2*x)-exp(-2*x))+x;
}

int main(){
	vector <double> sol;
        vector <double> xinterval;

        //{
        cout << "for the dif equation: y''= 4*y - 4*x, boundary conditions: x0=0,xf=1,y0=0,yf=2" << endl;
        int N=9;
        FiniteDifEqSol tridiagsysDE(&pf,&qf,&rf,N);
        sol = tridiagsysDE.PrintSolution();
        xinterval = tridiagsysDE.getxinterv(); 
        cout << "\n" << endl; 
        cout << "Comparing with the analitical solution \n" << endl;
        cout << fixed << setw(20) << left << "FinDif Aprox w" << setw(20) << left << "|w - analytic y|" << endl;      
	for (int ii=1; ii<=N; ii++){         
		cout << fixed  << setw(20)<< left << sol[ii] << setw(20) << left << abs(sol[ii]-analiticsol(xinterval[ii])) << endl;
        }
        //}
        return 0;
}

