#include <cmath>
#include <vector>
#include "ClassCircular.h"

using namespace std;


Circular::Circular(double _radio,double _frecuencia,double _fase,double _Dt, double _tTotal){ // Nuestro constructor
	radio = _radio;
	frecuencia = _frecuencia;
	fase = _fase;
	Dt = _Dt;
	tTotal = _tTotal;
}

Circular::~Circular(){ // destructor

	cout<<"La clase Circular ha sido destruida"<<endl;
}

void Circular::establecerradio(double r){ // establecemos y obtenemos los valores ingresados por main
	radio = r;

}

double Circular::obtenerradio() const{
	return radio;

}

void Circular::establecerfrecuencia(double w){
	frecuencia = w;

}

double Circular::obtenerfrecuencia() const{
	return frecuencia;

}

void Circular::establecerfase(double f) {
	fase = f;

}

double Circular::obtenerfase() const{
	return fase;

}

void Circular::establecerDt(double dt){
	Dt = dt;

}

double Circular::obtenerDt() const{
	return Dt;

}

void Circular::establecertTotal(double tT){
	tTotal = tT;

}

double Circular::obtenertTotal() const{
	return tTotal;

}

vector<double> Circular::tiempo(){ // vector de tiempo, donde guardaremos los pasos de tiempo, el cronométro
	vector<double> tiempo;
	for(int i=0; i<=tTotal/Dt;i++){
		tiempo.push_back(Dt*i);
	}
	
	return tiempo;

}
	
vector<double> Circular::xpos(){ // guardamos el recorrido en x
	vector<double> xpos;
	vector<double> tiemp = tiempo();	
	for(int i=0; i<=tTotal/Dt;i++){
		xpos.push_back(radio*cos(frecuencia*tiemp[i]+fase));
	}
	
	return xpos;

}

vector<double> Circular::ypos(){ // guardamos el recorrido en y
	vector<double> ypos;
	vector<double> tiemp = tiempo();	
	for(int i=0; i<=tTotal/Dt;i++){
		ypos.push_back(radio*sin(frecuencia*tiemp[i]+fase));
	}
	
	return ypos;

}

