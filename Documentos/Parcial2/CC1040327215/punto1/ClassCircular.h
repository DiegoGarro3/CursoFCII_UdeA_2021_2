#include <iostream>
#include <vector> 


using namespace std;

class Circular{
	private:
		float radio; // radio del ciruclo
		float frecuencia; // frecuencia del movimiento
		float fase; // fase
		float Dt;
		float tTotal;
	
	public:
		Circular(float,float,float, float,float);// constructor
		~Circular();//destructor
		
		void establecerradio(float);
    		float obtenerradio();
    
    		void establecerfrecuencia(float);
    		float obtenerfrecuencia();
    
    		void establecerfase(float);
		float obtenerfase();
    
    		void establecerDt(float);
    		float obtenerDt();
    
    		void establecertTotal(float);
    		float obtenertTotal();
    
    		vector<float>  tiempo(float,float);
		vector<float>  xpos(float,float,float,float,float);
		vector<float>  ypos(float,float,float,float,float);


};
