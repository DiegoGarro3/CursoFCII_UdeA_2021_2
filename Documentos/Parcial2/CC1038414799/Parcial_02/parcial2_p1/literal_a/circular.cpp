#include<iostream>
#include<cmath>
#include <fstream>
#include<iomanip>


#include "circular.h"

using namespace std;

//Constructor to set parameters
Circular::Circular(double _radius, double _frecuency, double _phase, double _dt, double _time)

{
    setRadius(_radius);
    setFrecuency(_frecuency);
    setPhase(_phase);
    setDt(_dt);
    setTime(_time);
    //setIntervals();
}
//Destructor
Circular::~Circular()
{
    
}


//Defining set functions

void Circular::setRadius(double rad)
{
    //Assueres radius is positive if user puts a negative number
    if (rad<0)
    {
        radius = -rad;
    }
    
    else
        radius=rad;
} 


void Circular::setFrecuency(double frec)
{
    frecuency = frec;
} 


void Circular::setDt(double _dt)
{
    //Assueres dt is positive if user puts a negative number
    if (_dt<0)
    {
        dt = - _dt;
    }
    
    else
        dt=_dt;
}

void Circular::setTime(double t)
{
    //Assueres time is positive if user puts a negative number
    if (t<0)
    {
        time = - t;
    }
    
    else
        time = t ;
} 

void Circular::setPhase(double alpha)
{
    phase=alpha;
}


//Defining get functions

double Circular::getRadius() const
{
    return radius;
} 

double Circular::getFrecuency() const
{
    return frecuency;
} 


double Circular::getDt() const
{
    return dt;
} 


double Circular::getTime() const
{
    return time;
} 

double Circular::getPhase() const
{
    return phase;
} 

//Define equation of motion for x
double Circular::xpos(double t) const
{
    double x;
    x= radius*cos(frecuency*t+phase);
    return x;
}

//Define equation of motion for y
double  Circular::ypos(double t) const
{
    double y;
    y= radius*sin(frecuency*t+phase);
    return y;
}

//Principal function 
void Circular::motion2D() const
{
    //Initialization of ouput file
    ofstream dataOut( "motion_2D.dat" );

    if ( dataOut.fail() )      
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }

    //writing ouput file header
    dataOut << setw(4) << "time" 
    << setw(13) << setiosflags(ios::right) 
    << "x_pos" << setw(13) 
    << "y_pos"<< endl;

    double x_t = 0;
    double y_t = 0;
    double t =0;

    //calculate equation of motion for a time t with dt steps
    while (t <= time)
    {
        t+=dt;
        x_t = xpos(t);
        y_t = ypos(t);

        //saving values to ouput file
        dataOut << setw(4) << t 
        << setw(13) << x_t << setw(13) << y_t << endl;
    }

    //close ouput file 
    dataOut.close();
}



