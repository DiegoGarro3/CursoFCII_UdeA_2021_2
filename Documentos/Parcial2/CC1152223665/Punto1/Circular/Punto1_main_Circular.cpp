#include "Punto1_clase_Circular.h"
#include<iostream>
#include<vector>
#include<iomanip>
#include<fstream>
#include<cmath>

using namespace std;

int main(){
	
	double r=1.5;
	double dt=0.1;
	double T=3.2;
	double w=2.0;
	double a=M_PI/4.0;
	
	Circular circular = Circular(r,dt,T,w,a);
	
	vector<double> xpos = circular.xpos();
	
	vector<double> ypos = circular.ypos();
	
	//se muestra en pantalla los datos
	cout<<setw(8)<<left<<"Tiempo"<<setw(15)<<"Xpos"<<setw(15)<<"Ypos"<<endl;
	
	int dim_t= circular.obtenerT_total()/circular.obtenerDelta_t();
	
	vector<double> t=circular.time();
	
	for(int i=0;i<dim_t+1;i++){
		cout<<setw(8)<<left<<t[i]<<setw(15)<<xpos[i]<<setw(15)<<ypos[i]<<endl;
	}
	
	//se escriben los datos en un archivo .txt
	ofstream datos;
  
  	datos.open("DatosXposYpos.txt",ios::out); //abrimos archivo
  
  	if(datos.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	}
  	
  	//escribo los datos en el archivo de texto
  	datos<<setw(8)<<left<<"Tiempo"<<setw(15)<<"Xpos"<<setw(15)<<"Ypos"<<endl;
  	
  	for(int i=0;i<dim_t+1;i++){
		datos<<setw(8)<<left<<t[i]<<setw(15)<<xpos[i]<<setw(15)<<ypos[i]<<endl;
	}
	
	return 0;
}









