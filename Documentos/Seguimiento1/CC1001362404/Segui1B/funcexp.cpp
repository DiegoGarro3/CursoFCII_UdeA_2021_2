#include <iostream>
#include <cmath>
#include "funcexp.h"


using namespace std;

funcexp::funcexp(float xx, int kk) {
    x = xx;
    k = kk;
}

int funcexp::factorial(unsigned int number){
    
    int product = 1;
    
    if(number==0 or number==1){
        product=1;
    }
    else{
        for(int i=1; i <= number; ++i){
           product*=i;
        }   
    }
    return product;
}

void funcexp::compute() {
    resultado = 0; 
    for (int n = 0; n < k; n++)
    {
        resultado += pow(x, n) / factorial(n);
	
    }
}

void funcexp::Result(){
		
	cout << "La exponencial evaluada en " << x << " con " << k << " términos en la serie de Maclaurin es " << resultado << "\n" << "El valor real es " << exp(x) << endl;
}
