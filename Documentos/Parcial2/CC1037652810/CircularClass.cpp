#include <iostream>
#include <vector>
#include <cmath>
#include "CircularCProtot.h"

using namespace std;

Circular::Circular(double rad, double delt, double Tt, double angfre, double f)
  : Radio(rad), Deltat(delt), Ttotal(Tt), W(angfre), Fase(angfre)
{

}

Circular::~Circular(){
	cout<< "Circular class constructor deleted" << endl;
}

double Circular::getRadio() const{
	return Radio;
}

double Circular::getDeltat() const{
	return Deltat;
}

double Circular::getTtotal() const{
	return Ttotal;
}

double Circular::getOmega() const{
	return W;
}

double Circular::getFase() const{
	return Fase;
}
vector<double> Circular::Time(){
	int tsize = Ttotal/Deltat;
	for(int i=0; i<tsize; i++){
	   timevect.push_back(i*Deltat);
	}
	
	return timevect;
}

vector<double> Circular::Xpos(){
	int tsize = Ttotal/Deltat;
	vector<double> tiempo = Time();
	for(int i=0; i<tsize; i++){
		xpos.push_back( Radio*cos(W*tiempo[i] + Fase) );
	}
	
	return xpos;
}

vector<double> Circular::Ypos(){
	int tsize = Ttotal/Deltat;
	vector<double> tiempo = Time();
	for(int i=0; i<tsize; i++){
		ypos.push_back( Radio*sin(W*tiempo[i] + Fase) );
	}
	
	return ypos;
}



