#include <cmath>
#include <iomanip>
#include <iostream>
#include <fstream> // flujo de archivo

#include "ciruclar.h"

using namespace std;

circular:: circular(double R,double w, double dt, double t, double phase){

        setRadio(R);
        setFrecuencia(w);
        setIntervalo(dt);
        setTiempo(t);
        setPhase(phase);
};

circular::~circular(){
        cout << "fin de la clase" << endl;
};

void circular::setRadio(double R){
    radio=R;
};
double circular::getRadio() const {
    return radio;
};

void circular::setFrecuencia(double w){
    omega=w;
};

double circular::getFrecuencia() const {
    return omega;
} ;

void circular::setIntervalo(double dt){
    Dt=dt;
};
double circular::getIntervalo()const{
    return Dt;
} ;

void circular::setTiempo(double t){
    tiempo=t;
};

double circular::getTiempo() const {
    return tiempo;
} ;

void circular::setPhase(double phase){
    pha=phase;
};
double circular::getPhase() const {
    return pha;
} ;

double circular::Xpos(double time) const{
    double X;
    X=radio*cos(omega*time+pha);
    return X;
};

double circular::Ypos(double time) const{
    double Y;
    Y=radio*sin(omega*time+pha);
    return Y;
        
};
//Lectura del archivo.
void circular::Motion(){

    ofstream CircularMotion("Motion2d.txt" ); //Escribe un archivo

	if ( CircularMotion.fail() ){   // misma cosa    
            
        cout << "No se pudo abrir el archivo" << endl;
            exit( 1 );
    }

    double time{0};
    while (time<=tiempo)
    {
        CircularMotion << left << setw(13) << Xpos(time)  << setw(13) << Ypos(time) << endl;
        time+=Dt;
            
    }
}

        
        


