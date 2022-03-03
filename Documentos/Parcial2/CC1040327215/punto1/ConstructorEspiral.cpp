#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include "ClassEspiral.h"

using namespace std;

Espiral::Espiral(float _radio,float _frecuencia,float _fase,float _Dt, float _tTotal, float _z0, float _vz) 
: Circular( _radio,_frecuencia,_fase,_Dt,_tTotal){ // inicializamos el constructor con la herencia

        z0 = _z0;
        vz = _vz;
}

Espiral::~Espiral(){ // destructor

        cout<<"La clase Espiral ha sido destruida"<<endl; // notificamos
}

void Espiral::establecerz0(float zcero){ // establecemos y obtenemos z0, vz
	z0 = zcero;
}

float Espiral::obtenerz0(){
	return z0;
}

void Espiral::establecervz(float vzeta){
	vz = vzeta;
}

float Espiral::obtenervz(){
	return vz;
}

vector<float> Espiral::zpos(float z0,float vz){ // guardamos el recorrido en y
	vector<float> zpos;
	vector<float> Tiempo = Circular::tiempo(Circular::obtenerDt(),Circular::obtenertTotal());
	int tam = Circular::obtenertTotal()/Circular::obtenerDt();
	for(int i=0; i<=tam;i++){
		zpos.push_back(z0 + vz*Tiempo[i]);
	}
	
	return zpos;

}




