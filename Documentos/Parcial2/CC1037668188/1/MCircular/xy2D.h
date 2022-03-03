#ifndef MOVIMIENTO2D_H
#define MOVIMIENTO2D_H
#include<iostream>
#include<vector>
using namespace std;

class Circular
{
    public:
    Circular(double, double, double , double , double);
    ~Circular();
    double getradio(void);
    void setradio(double);
    double getfrecuencia(void);
    void setfrecuencia(double);
    double getdeltaT(void);
    void setdeltaT(double);
    double getTiempo(void);
    void setTiempo(double);
    double getfase(void);
    void setfase(double);
    vector<double> xpos(void);
    vector<double> ypos(void);
    vector<double> T(void);


    private:
    double radio;
    double frecuencia;
    double dt;
    double time;
    double phase;

};
#endif