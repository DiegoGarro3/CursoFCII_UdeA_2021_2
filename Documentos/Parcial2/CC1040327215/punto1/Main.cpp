
#include "ClassEspiral.h"
#include<iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;



int main(){

	float r = 1.5; // datos ingresados por el usuario
	float frecuencia = 2;
	float fase = M_PI/4;
	float Dt = 0.1;
	float tTotal = 3.2;
	float z0 = 0.5;
	float vz = 2.1;
	
	// ejecutamos la clase para obtener la posición en el espacio y el tiempo

	Espiral espiral =  Espiral(r,frecuencia,fase,Dt,tTotal,z0,vz);
	
	vector<float> xpos = espiral.xpos(r,frecuencia,fase,Dt,tTotal); 
	vector<float> ypos = espiral.ypos(r,frecuencia,fase,Dt,tTotal);
	vector<float> zpos = espiral.zpos(z0,vz);
	vector<float> tiemp = espiral.tiempo(Dt,tTotal);
	
	// imprimimos los resultados en una tabla
	
	cout<<setw(7)<<left<<"Tiempo"<<setw(15)<<"xpos"<<setw(15)<<"ypos"<<setw(15)<<"zpos"<<endl;
	int tam = tTotal/Dt;
	for(int i=0; i<=tam;i++){
	
		cout<<setw(7)<<left<<tiemp[i]<<setw(15)<<xpos[i]<<setw(15)<<ypos[i]<<setw(15)<<zpos[i]<<endl;
	
	}
	
	// ahora vamos a guardar las posiciones en un archivo .txt
	
	ofstream archivoSalida( "posicion.txt", ios::out );
	
        if ( archivoSalida.fail() )   //si no carga bien el archivo, imprimimos que hay un error al cargarlo
    {
      cout << "No se pudo abrir el archivo" << endl;
      exit( 1 );
    }
     archivoSalida<<setw(7)<<left<<"Tiempo"<<setw(15)<<"xpos"<<setw(15)<<"ypos"<<setw(15)<<"zpos"<<endl; // guardamos los datos en .txt
        for(int i=0; i<=tam;i++){
	
		archivoSalida<<setw(7)<<left<<tiemp[i]<<setw(15)<<xpos[i]<<setw(15)<<ypos[i]<<setw(15)<<zpos[i]<<endl;
	
	}
	
	



return 0;

}
