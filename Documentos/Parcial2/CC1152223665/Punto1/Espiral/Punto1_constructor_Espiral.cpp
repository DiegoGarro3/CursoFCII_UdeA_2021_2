#include<vector>
#include<iostream>
#include"Punto1_clase_Espiral.h"

using namespace std;

Espiral::Espiral(double r, double dt, double T, double w, double f, double z0, double vz) 
: Circular(r, dt, T, w, f )
{

	establecerZ0(z0);
	establecerVz(vz);
}

Espiral::~Espiral(){
	cout<<"Destructor de Espiral"<<endl;
}

//Funcion establecer para cada dato lo que hace es almacenar el argumento en una variable de la clase.
void Espiral::establecerZ0(double z0){ 
	Z0 = z0;
}
//Funcion obtener para cada dato lo que hace es retornar el valor de la variable, ya sea string, int o float. 
double Espiral::obtenerZ0() const{
	return Z0;
}

//getters y setters
void Espiral::establecerVz(double vz){ 
	Vz = vz;
}
double Espiral::obtenerVz() const{
	return Vz;
}

vector<double> Espiral::zpos(){
	vector<double> zpos;
	//invocamos variables privadas de la clase base a travez de las funciones obtener (get)
	int dim_t = Circular::obtenerT_total() / Circular::obtenerDelta_t();
	
	//invocamos la funcion con el vector de tiempo de la clase base
	vector<double> tiempo = Circular::time();
	
	for(int i=0; i<dim_t+1; i++){
		zpos.push_back( Z0 + Vz * tiempo[i] );
	}
	
	return zpos;
}




