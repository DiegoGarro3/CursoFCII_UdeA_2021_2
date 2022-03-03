#include <cmath>
#include <vector>
#include "ClassCircular.h"

using namespace std;


Circular::Circular(float _radio,float _frecuencia,float _fase,float _Dt, float _tTotal){ // Nuestro constructor
	radio = _radio;
	frecuencia = _frecuencia;
	fase = _fase;
	Dt = _Dt;
	tTotal = _tTotal;
}

Circular::~Circular(){ // destructor

	cout<<"La clase Circular ha sido destruida"<<endl;
}

void Circular::establecerradio(float r){ // establecemos y obtenemos los valores ingresados por main
	radio = r;

}

float Circular::obtenerradio(){
	return radio;

}

void Circular::establecerfrecuencia(float w){
	frecuencia = w;

}

float Circular::obtenerfrecuencia(){
	return frecuencia;

}

void Circular::establecerfase(float f){
	fase = f;

}

float Circular::obtenerfase(){
	return fase;

}

void Circular::establecerDt(float dt){
	Dt = dt;

}

float Circular::obtenerDt(){
	return Dt;

}

void Circular::establecertTotal(float tT){
	tTotal = tT;

}

float Circular::obtenertTotal(){
	return tTotal;

}

vector<float> Circular::tiempo(float Dt,float tTotal){ // vector de tiempo, donde guardaremos los pasos de tiempo, el cronométro
	vector<float> tiempo;
	for(int i=0; i<=tTotal/Dt;i++){
		tiempo.push_back(Dt*i);
	}
	
	return tiempo;

}
	
vector<float> Circular::xpos(float radio, float frecuencia, float fase, float Dt, float tTotal){ // guardamos el recorrido en x
	vector<float> xpos;
	vector<float> tiemp = tiempo(Dt,tTotal);	
	for(int i=0; i<=tTotal/Dt;i++){
		xpos.push_back(radio*cos(frecuencia*tiemp[i]+fase));
	}
	
	return xpos;

}

vector<float> Circular::ypos(float radio, float frecuencia, float fase, float Dt, float tTotal){ // guardamos el recorrido en y
	vector<float> ypos;
	vector<float> tiemp = tiempo(Dt,tTotal);	
	for(int i=0; i<=tTotal/Dt;i++){
		ypos.push_back(radio*sin(frecuencia*tiemp[i]+fase));
	}
	
	return ypos;

}

