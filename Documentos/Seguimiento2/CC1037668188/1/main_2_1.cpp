#include "segui2_1.cpp"
int main()
{
    int n;
    cout<<"Ingrese el tamaño de la muestra"<< endl;
    cin>>n;
    double a[n];
    cout<<"ingrese los valores de la muestra"<< endl;
    for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
    double prom;
    double var;
    Estadistica l;

    prom=l.Promedio(a,n);
    var=l.Varianza(a,n);
    cout<<"El promedio es: "<< prom<<endl;
    cout<<"La varianza es: "<< var<<endl;
    return 0;
}