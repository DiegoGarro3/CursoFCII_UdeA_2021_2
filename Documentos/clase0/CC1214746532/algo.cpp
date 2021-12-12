#include<iostream>
using std::cout;
using std::endl;
#include <math.h>

using namespace std;

double A;
double B;
double C;
double determinante;

int main()
{

    cout<< endl<< "Ingrese los valores A,B y C de la ecuacion AX^2 + Bx + C"<< endl<< endl;
    cout<< endl<< "Ingrese A"<< endl<< endl;
    cin >> A;
    cout<< endl<< "Ingrese B"<< endl<< endl;
    cin >> B;
    cout<< endl<< "Ingrese C"<< endl<< endl;
    cin >> C;

    determinante = B*B - 4*A*C;

    if (determinante<0){
        cout<< endl<< "La solucion es:"<< -B/2 << "+ i " << sqrt(-determinante)/2<<" y su complejo conjugado"<< endl<< endl;
    }
    else if (determinante == 0) {
        cout<< endl<< "La solucion es :"<< A/2 <<endl<< endl;
    } 
    else{
        cout<< endl<< "Las soluciones son :"<< (-B + sqrt(determinante))/2 << " y " << -(B + sqrt(determinante))/2 <<endl<< endl;
    }
}