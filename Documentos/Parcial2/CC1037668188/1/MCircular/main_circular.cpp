#include"xy2D.h"
#include<fstream>
#include<cmath>
#include<iomanip>
using namespace std;


int main()
{
    double Rad=1.5;
    double Frecuencia=2.0;
    double dtt=0.1;
    double t=3.2;
    double alp=M_PI/4.;
    
    Circular MovCir(Rad,Frecuencia,dtt,t,alp);
    vector<double>Tiempo=MovCir.T();
    vector<double>pos_x=MovCir.xpos();
    vector<double>pos_y=MovCir.ypos();

    
    
    ofstream Archivo_salida( "Circular_salida.csv" );
  
  	if(Archivo_salida.fail())
    {
		cout<<"No se pudo crear el archivo";
		exit(1);
  	};
    Archivo_salida<<"XPOS"<<","<<"YPOS"<<","<<"Time"<<endl;
    for(int k=0;k<pos_x.size();k++)
    {
        Archivo_salida<<pos_x[k]<<","<<pos_y[k]<<","<<Tiempo[k]<<endl;
    };
    Archivo_salida.close();
    return 0;
}
