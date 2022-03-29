#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>

#include "ForwardDiff.h"

using namespace std;

ForwardDiff::ForwardDiff(float alphaIn, float lIn, int mIn, float kIn, float tfIn) {
    alpha = alphaIn;
    l = lIn;
    m = mIn;
    k = kIn;
    tf = tfIn;
};

void ForwardDiff::setf(float (*fIn)(float)){
    f = fIn;
};

vector<vector<float>> ForwardDiff::getSolution(){
    float h = l / m;

    float lambda = alpha*alpha*k / (h*h);

    float numberTimesteps = static_cast<int> (tf / k) + 1;

    vector<vector<float>> A(m-1, vector<float>(m-1));
    vector<vector<float>> w(numberTimesteps, vector<float>(m-1));

    // Inicializar matriz A
    for (size_t i = 0; i < m - 1; i++) {
        for (size_t j = 0; j < m - 1; j++) {
            if (i == j) {
                A[i][j] = 1 - 2*lambda;
            }
            if (j == i - 1 || j == i + 1) {
                A[i][j] = lambda;
            }
        }
    }

    // Inicializar primera fila w0
    for (size_t i = 0; i < m - 1; i++) {
        w[0][i] = f(l*(i+1) / m);
    }
    
    // Calcular w_j = A w_(j-1)
    for (size_t j = 1; j < numberTimesteps; j++) {
        for (size_t i1 = 0; i1 < m - 1; i1++) {
            for (size_t i2 = 0; i2 < m - 1; i2++) {
                w[j][i1] += A[i1][i2]*w[j-1][i2];
            }
        }
    }

    saveFile(w);

    return w;

};

void ForwardDiff::saveFile(vector<vector<float>> w){
    ofstream datos("forward-data.txt");

	if (datos.fail()) {   
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }

    for (size_t j = 0; j < static_cast<int> (tf / k) + 1; j++) {
        datos << setw(13) << 0.;
        for (size_t i = 0; i < m - 1; i++) {
            datos << setw(13) << w[j][i];
        }
        datos << setw(13) << 0. << endl;
    }

    datos.close();
};