#ifndef CIRCULAR_H
#define CIRCULAR_H

#include<vector>

using namespace std;

class Circular {
	private:	//atributos
		double Radio;
		double Delta_t;
		double T_total;
		double Omega;
		double Fase;
		
	public: //metodos
		Circular(double, double, double, double, double); //constructor
		~Circular(); //destructor
		
		//getters y setters
		void establecerRadio( double);
		double obtenerRadio() const;
		
		void establecerDelta_t( double);
		double obtenerDelta_t() const;
		
		void establecerT_total( double);
		double obtenerT_total() const;
		
		void establecerOmega( double);
		double obtenerOmega() const;
		
		void establecerFase( double);
		double obtenerFase() const;
		
		vector<double> time();
		vector<double> xpos();
		vector<double> ypos();
		
};
#endif
