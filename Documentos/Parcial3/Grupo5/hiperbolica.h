#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>

using namespace std;

class Hiperbolica //Creacion de una clase llamada Ecuacion
{
    public: //Declaracion de las funciones publicas
        
        Hiperbolica(double,double,double,double,int,double,double, double (*)(double),double (*)(double),double (*)(double,double));//Constructor de la clase
        ~Hiperbolica();//Destructor de la clase
        vector<vector<float>> solucion(void);
        void set_x(void);
        void set_t(void);
        
        //En .cpp se halla una breve descripcion de lo que hace cada funcion


    private: //Declaracion de las variables privadas

        // coeficientes que dan forma a la EDP
        double alfa;
        // Dominio
        double l;// largo
        double t_final;
        //pasos que definen la malla
        int m;//numero partiones del intervalo [0,l]
        double k;  //delta t
        double h; //delta x
        int jmax; //numero de particiones del intervalo [0,t_final]
        vector<double>x;
        vector<double>T;
        double v0;
        double vl;
        double (*f)(double);
        double (*g)(double);
        double (*rho)(double,double); //fuente


};