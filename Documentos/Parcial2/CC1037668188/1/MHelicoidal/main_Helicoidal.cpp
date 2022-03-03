#include"xyz3D.h"
#include<fstream>
using namespace std;
#include<iomanip>
#include<cmath>

int main()
{
    double Rad=1.5;
    double Frecuencia=2.0;
    double dtt=0.1;
    double t=3.2;
    double alp=M_PI/4.;
    double zini=0.5;
    double Vzini=2.1;

    Helicoidal MovHel(Rad,Frecuencia,dtt,t,alp,zini,Vzini);
    vector<double>Tiempo=MovHel.T();
    vector<double>pos_x=MovHel.xpos();
    vector<double>pos_y=MovHel.ypos();
    vector<double>pos_z=MovHel.zpos();

    ofstream Archivo_salida2( "Helicoidal_salida.cvs" );
  
  	if(Archivo_salida2.fail())
    {
		cout<<"No se pudo crear el archivo";
		exit(1);
  	};
    Archivo_salida2<<"XPOS"<<","<<"YPOS"<<","<<"ZPOS"<<","<<"Time"<<endl;
    for(int k=0;k<pos_x.size();k++)
    {
      Archivo_salida2<<pos_x[k]<<","<<pos_y[k]<<","<<pos_z[k]<<","<<Tiempo[k]<<endl;
    };
    Archivo_salida2.close();
  









    return 0;
}