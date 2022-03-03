#include <iostream>
#include <cmath>
#include "stad.h"

using namespace std;

estadistica::estadistica(double xx[], int num){
    n = num;
    x[n];
    for (int i = 0; i < n; i++){
        x[i] = xx[i];
    }
    
    calcavg();
    variance();
    
        
}

double estadistica::calcavg(){
    
    double suma = 0.0;
    for (int i = 0; i < n; i++){
        suma +=  x[i];
    }
    
    avg = suma / n;
    
    return (avg);
    
}


double estadistica::variance(){
    
    double suma = 0.0;
    for (int i = 0; i < n; i++){
        suma +=  pow((x[i]-avg),2);
    }
    
    var = suma / n;
    
    return (var);
    
}


