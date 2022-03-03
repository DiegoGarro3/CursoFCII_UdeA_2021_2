#include<iomanip>
#include"Ecuaciones.h"

Equa::Equa(vector<vector<double>>Matriz,vector<double>h)
{
    Mat=Matriz;
    b=h;
};

vector<double> Equa::jacobi(vector<double>x_0,int iter)
{
    vector<double>x_k=x_0;
    vector<double>x_k1=x_0;
    for(int k=0;k<=iter;k++)
    {
        for(int i=0;i<x_k.size();i++)
        {
            double suma=b[i]/(Mat[i][i]);
            for(int j=0;j<x_k.size();j++)
            {
                if(j==i)
                continue;
                suma=suma-(Mat[i][j]*x_k[j])/(Mat[i][i]);
                
            }
            x_k1[i]=suma;
        }
    x_k=x_k1;
    

    }
    return x_k1;
};


vector<double> Equa::SOR(vector<double>x_0,double w,int iter)
{
    vector<double>x_k=x_0;
    vector<double>x_k1=x_0;
    for(int k=0;k<=iter;k++)
    {
        for(int i=0;i<x_k.size();i++)
        {
            double suma=(1-w)*x_k[i]+w*b[i]/(Mat[i][i]);
            for(int j=0;j<i;j++)
            {
                suma=suma-w*(Mat[i][j]*x_k1[j])/(Mat[i][i]);
            }
            for(int j=i+1;j<x_k.size();j++)
            {
                suma=suma-w*(Mat[i][j]*x_k[j])/(Mat[i][i]);
            };
            x_k1[i]=suma;
        }
    x_k=x_k1;

    }
    return x_k1;
};



