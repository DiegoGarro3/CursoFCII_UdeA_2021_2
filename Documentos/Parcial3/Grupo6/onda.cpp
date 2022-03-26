#include "hiperbolica.h"
#include <fstream>

double fx(double);
double gx(double);
double rhox(double,double);
ofstream onda;

int main()
{   //parametros
    double alfa=0.4;
    double l=1.0;
    double time=1.0;
    double dt=0.05;
    double u_x0l=0;
    int par=50;  //partiones del interval[0,1]
    Hiperbolica Onda(alfa,l,time,dt,par,u_x0l,u_x0l,fx,gx,rhox);
    vector<vector<float>>W_ij=Onda.solucion();
    W_ij=Onda.solucion();

    onda.open("onda.csv");//se abre un archivo csv

    if(onda.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	}

    for (int i = 0; i <=par; i++)
    {

        if(i!=par){
            onda<<"x= "<<i*(l/par)<<",";
        }
        else{
            onda<<"x= "<<i*(l/par);
        }
    }


    for (int i = 0; i <= time/dt ; i++){
        
        onda<<"\n";    
        for (int j = 0; j <= par; j++)
        {
            if(j!=par){

                onda<<W_ij[i][j]<<",";//se va llenando el archivo
            }

            else{

                onda<<W_ij[i][j];
            }
        }
    }

    onda.close();//se cierra el archivo
    return 0;
};

double fx(double s)
{
    return sin(5*M_PI*s);
};

double gx(double s)
{
    return 0.0;
};
double rhox(double xx,double tt)
{
    return 0.0;
};