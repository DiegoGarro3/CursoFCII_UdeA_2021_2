#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "ClassEspiral.h"

using namespace std;

Espiral::Espiral(double _radio,double _frecuencia,double _fase,double _Dt, double _tTotal, double _z0, double _vz) 
: Circular( _radio,_frecuencia,_fase,_Dt,_tTotal){ // inicializamos el constructor con la herencia

        z0 = _z0;
        vz = _vz;
}

Espiral::~Espiral(){ // destructor

        cout<<"La clase Espiral ha sido destruida"<<endl; // notificamos
}

void Espiral::establecerz0(double zcero){ // establecemos y obtenemos z0, vz
	z0 = zcero;
}

double Espiral::obtenerz0() const{
	return z0;
}

void Espiral::establecervz(double vzeta){
	vz = vzeta;
}

double Espiral::obtenervz() const{
	return vz;
}

vector<double> Espiral::zpos(){ // guardamos el recorrido en y
	vector<double> zpos;
	vector<double> Tiempo = Circular::tiempo();
	int tam = Circular::obtenertTotal()/Circular::obtenerDt();
	for(int i=0; i<=tam;i++){
		zpos.push_back(z0 + vz*Tiempo[i]);
	}
	
	return zpos;

}




