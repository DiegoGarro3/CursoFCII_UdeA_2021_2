#include "helice.h"

vector<float> x;
vector<float> y;
vector<float> z;
vector<float> tt;

ofstream figura;

int main(){

    Espiral mov;//se crea el objeto espiral
    tt = mov.t();
    x = mov.xpos();
    y = mov.ypos();
    z = mov.zpos();

    figura.open("figura.csv");//se abre un archivo csv

    if(figura.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	}

    figura<<"Tiempo,"<<"x,"<<"y,"<<"z"<<endl;//el header del archivo csv
    //no se hace el espaciado de setw(5) porque cada espacio entra como parte del
    //nombre y python reconoce a cada espacio haciendo fea su lectura

    /*las comas son para poder separar cada elemento y que el programa que lo 
    abra pueda separarlos por columan y no interprete las comas*/

    for (int i = 0; i <= mov.Obtener_Intervalos() ; i++){
        
        figura<<tt[i]<<","<<setw(5)<<x[i]<<","<<setw(5)<<y[i]<<","<<setw(5)<<z[i]<<endl;//se va llenando el archivo
    }

    figura.close();//se cierra el archivo
}