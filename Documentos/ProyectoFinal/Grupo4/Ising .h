#include<vector>
#include<cmath>
#include<time.h>
#include <chrono>
#include <random>
#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

class Ising
{
private:

    int STEPS;

    int SIZE;

    float T;

    float J;

    int Reverse;

    float H;

    float delta_H;
   
public:

    Ising(int, int, float ,float, int,float, float );

    ~Ising();

    void Setsteps(int);

    void Setsize(int);

    void SetJ(int);

    void SetTemperature(int);
    

    float randomUniform();

    int pbc(int);

    float Hamiltonian(vector<vector<float>>, float, int,int);

    vector<vector<float>> Spin();

    vector<vector<float>> Metropolis(float);


    float Magnetizacion(vector<vector<float>>);

    void GetSolution();

    void GetSpin();





};








