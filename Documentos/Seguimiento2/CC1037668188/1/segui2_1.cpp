#include "segui2_1.h"
#include<cmath>

Estadistica::Estadistica(void)
{
};

double Estadistica::Promedio(double a[],int n )
{
    double suma=a[0];
    for(int i=1;i<n;i++)
        suma=suma+a[i];
    return suma/n;
};
double Estadistica::Varianza(double a[],int n)
{
    double suma=0;
    double prom=Promedio(a,n);
    for(int i=0;i<n;i++)
    suma=suma+pow(a[i]-prom,2);
    return suma/n;
};


