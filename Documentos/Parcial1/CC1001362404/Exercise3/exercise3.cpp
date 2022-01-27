//Libraries
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

//defining Ordinary Differential Equation (ODE) to be solved 
#define f(x,y) (y - x*x + 1)

//Solving methods for ODE:
void euler(float, float, float, float);
void runge_kutta(float, float, float, float);

//Main code

int main()
{
 float x0, y0, xn;
 int n;

 cout<<"Enter Initial Condition"<< endl;
 cout<<"x0 = ";
 cin>> x0;
 cout<<"y0 = ";
 cin >> y0;
 cout<<"Enter calculation point xn = ";
 cin>>xn;
 cout<<"Enter number of steps: ";
 cin>> n;

 cout<<endl; 
 runge_kutta(x0, y0, n, xn);
 
 cout<<endl;
 euler(x0, y0, n, xn);
 
 cout<<endl;
 
 return 0;


}


//Implementation of the solving methods

void runge_kutta(float x0, float y0, float n, float xn)
{
	float yn, h, k1, k2, k3, k4, k;
	int i;
	
	// Calculating step size (h)
	h = (xn-x0)/n;
	
	
	cout<<"\n//////////////////////////////////////////\n";
	cout<<"            RUNGE KUTTA FOUR                ";
	cout<<"\n//////////////////////////////////////////\n";
	
	cout << setw(10) << "x0" << setw(10) << "y0" << setw(10) <<"yn" << endl;
	cout<<"    ---------------------------\n";

	for(i=0; i < n; i++)
	{
	k1 = h * (f(x0, y0));
	k2 = h * (f((x0+h/2), (y0+k1/2)));
	k3 = h * (f((x0+h/2), (y0+k2/2)));
	k4 = h * (f((x0+h), (y0+k3)));
	k = (k1+2*k2+2*k3+k4)/6;
	yn = y0 + k;

	cout << setw(10) << fixed << setprecision(3) << x0 << setw(10) << fixed << setprecision(3)<< y0 << setw(10)<< fixed << setprecision(3) << yn << endl;

	x0 = x0+h;
	y0 = yn;
	}

	/* Displaying result */
	cout<<"\nThe approximate solution of y at x = "<< xn<< " is " << yn << endl;

}

void euler(float x0, float y, float n, float x)
{
	float temp = 0;
	float h;
	
	// Calculating step size (h)
	h = (x-x0)/n;
	
	cout<<"\n//////////////////////////////////////////\n";
	cout<<"                 EULER                      ";
	cout<<"\n//////////////////////////////////////////\n";
	cout << setw(10) << "x0" << setw(10) << "y0" << setw(10) <<"yn" << endl;
	cout<<"    ---------------------------\n";
	

	// Iterating till the point at which we
	// need approximation
	while (x0 < x) {
		temp = y;
		y = y + h * f(x0, y);
		x0 = x0 + h;
		cout << setw(10) << fixed << setprecision(3) << x0 << setw(10) << fixed << setprecision(3)<< temp << setw(10)<< fixed << setprecision(3) << y << endl;
		
		
	}

	// Printing approximation
	cout<<"\nThe approximate solution of y at x = "<< x << " is " << y << endl;
}
