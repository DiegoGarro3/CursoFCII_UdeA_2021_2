#include <iostream>
#include <vector> 
#ifndef CIRCULAR_H
#define CIRCULAR_H


using namespace std;

class Circular{
	private:
		double radio; // radio del ciruclo
		double frecuencia; // frecuencia del movimiento
		double fase; // fase
		double Dt;
		double tTotal;
	
	public:
		Circular(double,double,double, double,double);// constructor
		~Circular();//destructor
		
		void establecerradio(double);
    		double obtenerradio() const;
    
    		void establecerfrecuencia(double);
    		double obtenerfrecuencia() const;
    
    		void establecerfase(double);
		double obtenerfase() const;
    
    		void establecerDt(double);
    		double obtenerDt() const;
    
    		void establecertTotal(double);
    		double obtenertTotal() const;
    
    		vector<double>  tiempo();
		vector<double>  xpos();
		vector<double>  ypos();


};


#endif
