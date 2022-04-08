#include"path.h"
#include<iomanip>
#include<iostream>
#include<fstream>
#include<cmath>

using namespace std;

double Harmonic(double);

int main()
{
    double me=207*0.5*pow(10,6); //Mev/c²
    double omega=1.3*pow(10,22); // rad/s
    double v_c=3*pow(10,8);
    double hbar=6.582119624*pow(10,-16);
    double t=2*M_PI*20/omega;
    double x=3.5*pow(10,-14);
    int N=300;
    int M=301;
    int step=100000;
    srand(time(NULL));
    
    Path_Integral Oscilador(M,N,t,-x,x,Harmonic,me);
    vector<double>psi;
    vector<double>pos_x;
    pos_x=Oscilador.get_x();
    psi=Oscilador.camino(step);
    ofstream Archivo_salida( "wave_salida.csv" );
  	if(Archivo_salida.fail())
    {
		cout<<"No se pudo crear el archivo";
		exit(1);
  	};
    Archivo_salida<<"XPOS"<<","<<"PSI2"<<endl;
    for(int k=0;k<pos_x.size();k++)
    {
        Archivo_salida<<pos_x[k]<<","<<psi[k]<<endl;
    };
    Archivo_salida.close();
    






    return 0;
}

double Harmonic(double s)
{
    return pow(1.3,2)*pow(10,44)*207*0.5*pow(10,6)/(9*pow(10,16))*0.5*(pow(s,2));
};
