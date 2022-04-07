#include<iostream>
#include<vector>
#include<iomanip>
#include<stdlib.h>
#include <time.h>

using namespace std;

class Path_Integral
{
    public:
    Path_Integral(int,int,double,double,double,double(*)(double),double);
    void set_x(void);
    vector<double>get_x(void);
    int pbc(int);
    vector<double> camino(int);

    private:
    int M;
    int N;
    double time;
    double a;
    double b;
    double dx;
    double dt;
    vector<double>x;
    double mass;
    double (*Vx)(double);

};
