#include <cmath>
#include <iomanip>
#include<iostream>
#include <fstream> // flujo de archivo


#include "espiral.h"

using namespace std;

espiral::espiral(double R,double w, double dt, double t, double phase, double Zo, double Vo) : circular(R,w,dt,t,phase)
{
    setZo(Zo);
    setVo(Vo);

};
espiral::~espiral(){
    cout << "El objeto ha sido destruido" << endl;
};

void espiral::setZo(double Zo){
    Z0=Zo;
};

double espiral::getZo() const {
        return Z0;
};
void espiral::setVo(double Vo){
    V0=Vo;
};

double espiral::getVo() const {
    return V0;
};

void espiral::Motion3d(){

    ofstream CircularMotion3d("Motion3d.dat" ); //Escribe un archivo

        if ( CircularMotion3d.fail() ){   // misma cosa    
            
            cout << "No se pudo abrir el archivo" << endl;
            exit( 1 );
        }

    double time{0};
    double x{0};
    double y{0};
    double z{0};
    //Escritura del archvio Motion3d
    while (time<= circular::getTiempo())
    {   x=circular::Xpos(time);
        y=circular::Ypos(time);
        z=Z0+V0*time;
        CircularMotion3d << left << setw(13) << x  << setw(13) << y <<  setw(13) << z << endl;
        time+= circular::getIntervalo();
            
    }

};
