#include"hiperbolica.h"
#include <fstream>

//prototipos de f(x) y g(x)
double fx(double);
double gx(double);
double rhox(double,double);
ofstream tubo;

int main()
{   //parametros
    double alfa=1.0;
    double l=1.0;
    double time=3.0;
    double dt=0.05;
    int par=10;  //partiones del interval[0,1]
    double p_x0l=0.9;
    Hiperbolica Onda(alfa,l,time,dt,par,p_x0l,p_x0l,fx,gx,rhox);
    vector<vector<float>>W_ij=Onda.solucion();
    W_ij=Onda.solucion();

    tubo.open("tubo.csv");//se abre un archivo csv

    if(tubo.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	}

    for (int i = 0; i <=par; i++)
    {

        if(i!=par){
            tubo<<"x= "<<i*(l/par)<<",";
        }
        else{
            tubo<<"x= "<<i*(l/par);
        }
    }


    for (int i = 0; i <= time/dt ; i++){
        
        tubo<<"\n";    
        for (int j = 0; j <= par; j++)
        {
            if(j!=par){

                tubo<<W_ij[i][j]<<",";//se va llenando el archivo
            }

            else{

                tubo<<W_ij[i][j];
            }
        }
    }

    tubo.close();//se cierra el archivo



    return 0;
};

double fx(double s)
{
    return 0.9*cos(2*M_PI*s);
};

double gx(double s)
{
    return 0.0;
};
double rhox(double xx,double tt)
{
    return 0.0;
};


