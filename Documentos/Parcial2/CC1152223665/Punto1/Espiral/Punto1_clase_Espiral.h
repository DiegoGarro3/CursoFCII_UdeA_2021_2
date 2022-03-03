#ifndef ESPIRAL_H
#define ESPIRAL_H

#include<vector>
#include"../Circular/Punto1_clase_Circular.h"

using namespace std;

class Espiral: public Circular{
		
	public: //metodos
		Espiral(double, double, double, double, double, double, double); //construtor clase Espiral
		~Espiral(); //destructor clase Espiral
		
		//getters y setters
		void establecerZ0( double);
		double obtenerZ0() const;
		
		void establecerVz( double);
		double obtenerVz() const;
		
		vector<double> zpos();
		
	private: //atributos
		double Z0;
		double Vz;
};

#endif
