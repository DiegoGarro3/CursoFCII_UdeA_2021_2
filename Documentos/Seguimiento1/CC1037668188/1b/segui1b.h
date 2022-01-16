
//Definicion clase exponencial

#include <iostream> 
#include <cmath> 
#include<iomanip>


using namespace std;

class Exponencial
{
    public:
    Exponencial(void){    //constructor

    };

    long long  factorial(unsigned int m)   // funcion factorial
    {
        long long producto=1;
        for(int i=1;i<=m;i++){
            producto*=i;
        }
    return producto;
    };
    double Fun_Exp(double y, int l)      // funcion exponencial
    {
        double suma=0;
        for(int j=0;j<l;j++){
            suma+=(pow(y,j)/Exponencial::factorial(j));
        }
    return suma;
    };
    void display_exp(double z, int k)     // funcion que muestra en pantalla la exponencial.
    {          
        x=z;
        N=k;
        cout<<"La exponencial de "<< x << " via serie de taylor, para "<< N << " terminos de la serie es ";
        cout<<setiosflags(ios::showpoint) << setprecision(7)<<Exponencial::Fun_Exp(x,N)<<endl;
    };
private:

double x;     // variables privadas
int N;
};