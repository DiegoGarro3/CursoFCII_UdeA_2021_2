#include <iostream>
#include "funcexp.h"

int main(){
	float x_val;
	int n_val;
	 
	std::cout << "Ingrese el valor de la variable X y el orden de la expansión"<< std::endl;
	std::cin>>x_val;
	std::cin>>n_val;
	
	funcexp exponential(x_val,n_val);
	exponential.compute();
	exponential.Result();
	
	return 0;
}

/* Crece muy rápido !! (?)*/
