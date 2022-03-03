#include <fstream>

#include "Espiral.h"

using namespace std;

Espiral::Espiral(double _radio, double _angVel, double _Dt, double _tMax, double _fase, double _z0, double _vz0)
    :Circular (_radio, _angVel, _Dt, _tMax, _fase)
    {
    
        setZ0(_z0);
        setVz0(_vz0);
    
    }

Espiral::~Espiral(){

}

void Espiral::setZ0(double _z0){

    z0 = _z0;

}

void Espiral::setVz0(double _vz0){

    vz0 = _vz0;

}

double Espiral::getZ0(){

    return z0;

}

double Espiral::getVz0(){

    return vz0;

}

double Espiral::zPos(double _T){

    return z0 + vz0 * _T;

}

void Espiral::imprimirVars(){

    cout<<setw(5)<<"R:"<<setw(9)<<getRadio()<<endl;
    cout<<setw(5)<<"w:"<<setw(9)<<getVel()<<endl;
    cout<<setw(5)<<"dt:"<<setw(9)<<getDt()<<endl;
    cout<<setw(5)<<"T:"<<setw(9)<<getT()<<endl;
    cout<<setw(5)<<"a:"<<setw(9)<<getFase()<<endl;
    cout<<setw(5)<<"z0:"<<setw(9)<<getZ0()<<endl;
    cout<<setw(5)<<"a:"<<setw(9)<<getVz0()<<endl;
    
}

void Espiral::imprimirPos(double _T){

    cout<<"La posición de la partícula en el tiempo"<<setw(5)<<_T<<" es:"<<setw(5)<<xPos(_T)<<","<<setw(5)<<yPos(_T)<<setw(5)<<zPos(_T)<<endl;

}

void Espiral::generarArchivo(){

    ofstream outFile;
    outFile.open ("posiciónEspiral.txt");
    
    int N = getT() / getDt();
    int cont = 0;
    
    outFile << left << setw(5) << "time" << setprecision(5) << setw(10) << "xPos" << setprecision(5) << setw(10) << "yPos" << setprecision(5) << setw(10) << "zPos" <<endl;
    
    while(cont <= N){
    
        double time = cont * getDt();
        outFile << left << setw(5) << time << setprecision(5) << setw(10) << xPos(time)<< setprecision(5) << setw(10) << yPos(time) << setprecision(5) << setw(10) << zPos(time) <<endl;
        
        cont++;
    
    }
    
    outFile.close();
   

}
