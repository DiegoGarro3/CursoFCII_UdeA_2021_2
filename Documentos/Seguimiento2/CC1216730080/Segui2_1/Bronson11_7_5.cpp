#include <iostream>
#include <iomanip>
#include <math.h>

#include "stats.h"

int main(){

    const int size=14;
    int valores_prueba[size]={89,95,72,83,99,54,86,75,92,73,79,75,82,73};

    cout<<"El promedio del arreglo es"<<setw(5)<<calc_prom(valores_prueba,size)<<endl;
    cout<<"Y la varianza del arreglo es"<<setw(6)<<setprecision(4)<<varianza(valores_prueba,size)<<endl;    

}