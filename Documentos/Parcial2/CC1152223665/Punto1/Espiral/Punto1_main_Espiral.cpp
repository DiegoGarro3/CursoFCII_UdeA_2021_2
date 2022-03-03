#include"Punto1_clase_Espiral.h"
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
	double z0=0.5;
	double vz=2.1;
	
	Espiral espiral = Espiral(r,dt,T,w,a,z0,vz);
	
	vector<double> xpos = espiral.xpos();
	
	vector<double> ypos = espiral.ypos();
	
	vector<double> zpos = espiral.zpos();
	
	vector<double> t = espiral.time();
	
	//se muestra en pantalla los datos
	cout<<setw(8)<<left<<"Tiempo"<<setw(15)<<"Xpos"<<setw(15)<<"Ypos"<<setw(15)<<"Zpos"<<endl;
	
	int dim_t= espiral.obtenerT_total()/espiral.obtenerDelta_t();
		
	for(int i=0;i<dim_t+1;i++){
		cout<<setw(8)<<left<<t[i]<<setw(15)<<xpos[i]<<setw(15)<<ypos[i]<<setw(15)<<zpos[i]<<endl;
	}
	
	//se escriben los datos en un archivo .txt
	ofstream datos;
  
  	datos.open("DatosXposYposZpos.txt",ios::out); //abrimos archivo
  
  	if(datos.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	}
  	
  	//escribo los datos en el archivo de texto
  	datos<<setw(8)<<left<<"Tiempo"<<setw(15)<<"Xpos"<<setw(15)<<"Ypos"<<setw(15)<<"Zpos"<<endl;
  	
  	for(int i=0;i<dim_t+1;i++){
		datos<<setw(8)<<left<<t[i]<<setw(15)<<xpos[i]<<setw(15)<<ypos[i]<<setw(15)<<zpos[i]<<endl;
	}
	
	return 0;
}
