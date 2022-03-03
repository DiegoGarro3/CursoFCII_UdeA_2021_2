#include "circulo.h"

vector<float> x;
vector<float> y;
vector<float> tt;

int main(){

    //se corre el codigo para ver que si ejecute de forma correcta

    Circular mov;
    tt = mov.t();
    x = mov.xpos();
    y = mov.ypos();

    for (int i = 0; i <= mov.Obtener_Intervalos() ; i++){
        
        cout<<"Tiempo: "<<setw(5)<< tt[i] <<setw(5)<<"x: "<<setw(5)<<x[i]<<setw(5)<<" y: "<<setw(5)<<y[i]<<endl;  
    }   

    return 0;
}