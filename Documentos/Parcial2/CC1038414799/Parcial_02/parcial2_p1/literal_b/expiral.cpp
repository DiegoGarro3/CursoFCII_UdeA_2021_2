#include<iostream>
#include<iomanip>
#include<fstream>

#include "expiral.h"

using namespace std;

//Expiral constructor
Expiral::Expiral(double radio, double frecuencia, double fase, double delta, double tiempo,double z0, double vz) 
    //Calliing base class constructor
: Circular(radio,frecuencia,fase, delta, tiempo) 
{
    setZ0(z0);
    setVel_z(vz);
}

//Destructor
Expiral::~Expiral()
{
    cout << "En la carpeta encuentra un archivo .dat con los datos de la simulación." << endl;
}

//Define set functions
void Expiral::setZ0(double zIni)
{
    z_ini = zIni;
} 

void Expiral::setVel_z(double zVel)
{
    z_vel = zVel;
} 


//Define get functions
double Expiral::getZ0() const
{
    return z_ini;
} 

double Expiral::getVel_z() const
{
    return z_vel;
} 

//Principal function
void Expiral::motion3D()
{
    //initialization of ouput file
    ofstream dataOut( "motion_3D.dat" );

    if ( dataOut.fail() )      
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

    //writing ouput file header
    dataOut << setw(4) << "time" 
    << setw(13) << setiosflags(ios::right) << "x_pos" 
    << setw(13) << "y_pos"
    << setw(13) << "z_pos"<< endl;

    double x_t = 0;
    double y_t = 0;
    double z_t = 0;

    double t =0;
    
    //Calculus of spiral motion for a time t
    while (t <= Circular::getTime())
    {
        //using the parent class values using get functions
        t+=Circular::getDt();
        x_t = Circular::xpos(t);
        y_t = Circular::ypos(t);
        z_t = z_ini + z_vel*t; 

        //Write data to ouput file
        dataOut << setw(4) << t 
        << setw(13) << setprecision(5)<< x_t 
        << setw(13) << setprecision(5)<< y_t 
        << setw(13) << setprecision(5)<< z_t << endl;
    }

    //close ouput file 
    dataOut.close();
}












