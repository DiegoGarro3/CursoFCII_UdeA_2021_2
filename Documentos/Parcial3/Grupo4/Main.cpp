#include <iostream>
#include <iomanip>
#include "Clase.h"
#include <cmath>
using namespace std;

float Fuente(float x, float y){
    float f=x*exp(y);
    return f;
}

float BoundLeft(float x, float y){
    float G=0.0*y;
    return G;

}


float BoundRight(float x, float y){
    float G=2.0*exp(y);
    return G;

    
}


float BoundDown(float x, float y){
    float G=x;
    return G;
    
}


float BoundUp(float x, float y){
    float G=exp(1.0)*x;
    return G;
    
}

int main(){
    
    Poisson Placa(0,2,0,1,30,30,10000);
    Placa.setBUp(&BoundUp);
    Placa.setBDown(&BoundDown);
    Placa.setBLeft(&BoundLeft);
    Placa.setBRight(&BoundRight);
    Placa.setF(&Fuente);
    Placa.GetSolution();

}