#ifndef ECUACIONES_H
#define ECUACIONES_H
#include<iostream>
#include<vector>
using namespace std;

class Equa
{
    public:
    Equa(vector<vector<double>>,vector<double>);
    vector<double> jacobi(vector<double>,int);
    vector<double> SOR(vector<double>,double,int);
    private:
    vector<vector<double>>Mat;
    vector<double>b;

};
#endif