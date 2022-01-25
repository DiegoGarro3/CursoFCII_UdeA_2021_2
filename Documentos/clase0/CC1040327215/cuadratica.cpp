#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

int main()
{
	float a{0},b{0},c{0},x1{0},x2{0};
	
	cout <<"Ingrese el coefciente de X^2: ";
	cin >> a;
	
	cout <<"Ingrese el coeficiente de X: ";
	cin >> b;
	
	cout <<"Ingrese el coeficiente independiente: ";
	cin >> c;
	
	x1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a);
	x2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a);
	
	cout << "La primera raiz es:"<< x1 << endl;
	
	cout << "La segunda raiz es:"<< x2 << endl;
	
	return 0;
	
	
}
