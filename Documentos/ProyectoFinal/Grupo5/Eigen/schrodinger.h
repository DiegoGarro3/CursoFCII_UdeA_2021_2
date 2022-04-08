#include<iostream>
#include<cmath>
#include<iomanip>
#include <Eigen/Dense>

using namespace std;

class schrodinger //Creacion de una clase llamada Ecuacion
{
    public: //Declaracion de las funciones publicas
        
        schrodinger(double,double,int,double (*)(double),double);//Constructor de la clase
        ~schrodinger();//Destructor de la clase
        void set_x(void);
        void set_T(void);
        void set_vx(void);
        Eigen::MatrixXd get_H(void);
        int get_N(void);
        Eigen::VectorXd get_x(void);
        //En .cpp se halla una breve descripcion de lo que hace cada funcion


    private: //Declaracion de las variables privadas

        const double m_e=0.510998928*pow(10,6); // Masa del electrón en eV/c^2
        const double v_c=3*pow(10,8); // Velocidad de la luz en [m/s]
        const double hbar=6.582119624 * pow(10,-16); //Constante reducida de planck en [eV]
        int N;
        double x_inf;
        double x_sup;
        double (*V)(double);
        Eigen::VectorXd x;
        Eigen::MatrixXd T;
        Eigen::MatrixXd V_x;
        Eigen::MatrixXd H;
        double m;

};