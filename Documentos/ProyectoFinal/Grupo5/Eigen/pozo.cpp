#include "schrodinger.h"

double Vpot(double);
const double m_e=0.510998928*pow(10,6); // Masa del electrón en eV/c^2
const double v_c=3*pow(10,8); // Velocidad de la luz en [m/s]
const double hbar=6.582119624 * pow(10,-16); //Constante reducida de planck en [eV]

int main(){

    schrodinger pozo(-4*pow(10,-10),4*pow(10,-10),800,Vpot,m_e);
    Eigen::EigenSolver<Eigen::MatrixXd> solu(pozo.get_H());

    Eigen::MatrixXcd l = solu.eigenvalues();

    cout<<l<<endl;

}

double Vpot(double S){

    if(abs(S)<=2*pow(10,-10)){

        return -83*pow(10,6);
    }

    else{

        return 0;
    }
}