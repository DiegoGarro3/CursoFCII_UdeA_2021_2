#include"hiperbolica.h"
#include <fstream>

//prototipos de f(x) y g(x)
double fx(double);
double gx(double);
double rhox(double,double);
ofstream cuerda;

int main()
{   //parametros
    double l=3.0;
    double alfa=2*l*0.3;
    double time=3.0;
    double dt=0.01;
    int par=150;  //partiones del interval[0,1]
    double p_x0l=0;
    Hiperbolica Onda(alfa,l,time,dt,par,p_x0l,p_x0l,fx,gx,rhox);
    vector<vector<float>>W_ij=Onda.solucion();
    W_ij=Onda.solucion();

    cuerda.open("cuerda.csv");//se abre un archivo csv

    if(cuerda.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	}

    for (int i = 0; i <=par; i++)
    {

        if(i!=par){
            cuerda<<"x= "<<i*(l/par)<<",";
        }
        else{
            cuerda<<"x= "<<i*(l/par);
        }
    }


    for (int i = 0; i <= time/dt ; i++){
        
        cuerda<<"\n";    
        for (int j = 0; j <= par; j++)
        {
            if(j!=par){

                cuerda<<W_ij[i][j]<<",";//se va llenando el archivo
            }

            else{

                cuerda<<W_ij[i][j];
            }
        }
    }

    cuerda.close();//se cierra el archivo



    return 0;
};

double fx(double s)
{
    double h=0.3;

    if(s<1.5){

        return 2*h*s/3;
    }

    else{

        return 2*h*(1-s/3);
    }
};

double gx(double s)
{
    return 0.0;
};
double rhox(double xx,double tt)
{
    return 0.0;
};