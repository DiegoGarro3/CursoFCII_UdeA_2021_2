#include<iostream>
#include<vector>
#include<cmath>
#include"Punto1_clase_Circular.h"

using namespace std;

Circular::Circular(double r, double dt, double T, double w, double f){
	establecerRadio(r);
	establecerDelta_t(dt); 
	establecerT_total(T);
	establecerOmega(w);
	establecerFase(f);
}

Circular::~Circular(){
	cout<<"Destructor de Circular"<<endl;
}

//Funcion establecer para cada dato lo que hace es almacenar el argumento en una variable de la clase.
void Circular::establecerRadio(double r){ 
	Radio = r;
}
//Funcion obtener para cada dato lo que hace es retornar el valor de la variable, ya sea string, int o float. 
double Circular::obtenerRadio() const{
	return Radio;
}

//getters y setters
void Circular::establecerDelta_t(double dt){ 
	Delta_t = dt;
}
double Circular::obtenerDelta_t() const{
	return Delta_t;
}

void Circular::establecerT_total(double T){ 
	T_total = T;
}
double Circular::obtenerT_total() const{
	return T_total;
}

void Circular::establecerOmega(double w){ 
	Omega = w;
}
double Circular::obtenerOmega() const{
	return Omega;
}

void Circular::establecerFase(double f){ 
	Fase = f;
}
double Circular::obtenerFase() const{
	return Fase;
}

//funcion time de la clase que retorna un vector con el vector de tiempo
vector<double> Circular::time(){
   vector<double> timevect;
	int dim_t = T_total/Delta_t;
	
	for(int i=0; i<dim_t+1; i++){
	   timevect.push_back(i*Delta_t);
	}
	
	return timevect;
}

//funcion xpos que retorna un vector con las posiciones en x
vector<double> Circular::xpos(){
	vector<double> xpos;
	int dim_t = T_total/Delta_t;
	
	vector<double> tiempo = time();
	
	for(int i=0; i<dim_t+1; i++){
		xpos.push_back( Radio*cos(Omega*tiempo[i] + Fase) );
	}
	
	return xpos;
}

//funcion xpos que retorna un vector con las posiciones en y
vector<double> Circular::ypos(){
	vector<double> ypos;
	int dim_t = T_total/Delta_t;
	
	vector<double> tiempo = time();
	
	for(int i=0; i<dim_t+1; i++){
		ypos.push_back( Radio*sin(Omega*tiempo[i] + Fase) );
	}
	
	return ypos;
}



