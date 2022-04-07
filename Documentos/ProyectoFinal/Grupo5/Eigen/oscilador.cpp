#include "schrodinger.h"
#include <fstream>

ofstream datos;

double oscilador(double);
const double m_e=0.510998928*pow(10,6); // Masa del electrón en eV/c^2
const double v_c=3*pow(10,8); // Velocidad de la luz en [m/s]
const double hbar=6.582119624 * pow(10,-16); //Constante reducida de planck en [eV]

int main(){

    schrodinger muon(-3.5*pow(10,-14),3.5*pow(10,-14),600,oscilador,207*m_e);

    datos.open("datos.csv");//se abre un archivo csv

    if(datos.fail()){
		cout<<"No se pudo crear el archivo";
		exit(1);
  	}

    Eigen::EigenSolver<Eigen::MatrixXd> solu(muon.get_H());
    Eigen::MatrixXcd V = solu.eigenvectors();
    Eigen::MatrixXcd l = solu.eigenvalues();


    for(int i =0;i<muon.get_N()-1;i++){

        datos<<"\n";
        
        for(int j =0;j<muon.get_N()-1;j++){

            if(j==0){

                datos<<l(i)<<",0,";
            }

            datos<<V(i,j)<<",";

        }
        datos<<"0";

    }


    datos.close();//se cierra el archivo

}


double oscilador(double S){

    return (pow(1.3,2)*pow(10,44))*207*m_e/(pow(v_c,2))* 0.5*(pow(S,2));

}