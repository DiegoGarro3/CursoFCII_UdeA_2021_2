#include "hiperbolica.h"

Hiperbolica::Hiperbolica(double alpha, double xf,double tf,double dt,int particion,double v1, double v2,double (*fx)(double),double (*gx)(double),double (*rhoxt)(double,double))
{
    l=xf;
    k=dt;
    m=particion;
    alfa=alpha;
    t_final=tf;
    h=l/m;
    jmax=t_final/k;
    set_x();
    set_t();
    v0=v1;
    vl=v2;
    f=*fx;
    g=*gx;
    rho=*rhoxt;
};
Hiperbolica::~Hiperbolica()
{};

void Hiperbolica::set_x(void)
{
    vector<double>S(m+1,0);
    double h=l/m;
    for(int i=1;i<=m-1;i++)
    {
        S[i]=i*h;
    };
    x=S;
};

void Hiperbolica::set_t(void)
{
    vector<double>S(jmax,0);
    for(int j=1;j<=jmax;j++)
    {
        S[j]=j*k;
    }
    T=S;
};

vector<vector<float>> Hiperbolica::solucion()
{
    double lambda=alfa*k/h;
    vector<vector<float>>Malla(jmax+1);
    vector<float>wn0(m+1,v0);
    vector<float>wn1(m+1,v0);
    wn0[m]=vl;
    wn1[m]=vl;

    for(int n=1;n<=m-1;n++)
    {
        wn0[n]= (*f)(x[n]);
        wn1[n]=(1-pow(lambda,2))*(*f)(x[n])+pow(lambda,2)*((*f)(x[n+1])+(*f)(x[n-1]))/2 +k*(*g)(x[n])+pow(k,2)*(*rho)(x[n],0)/2.0;
    };

    Malla[0] = wn0;
    Malla[1] = wn1;

    for(int j=2; j<=jmax ;j++)
    {
        vector<float>wnj(m+1,v0);
        wnj[m]=vl;

        for(int i=1;i<=m-1;i++)
        {

            wnj[i]=pow(lambda,2)*(Malla[j-1][i-1]+Malla[j-1][i+1])+2*(1-pow(lambda,2))*Malla[j-1][i]-Malla[j-2][i]+(*rho)(x[i],T[j-1]);
        }
        
        Malla[j]=wnj;
    };

    return Malla;
}