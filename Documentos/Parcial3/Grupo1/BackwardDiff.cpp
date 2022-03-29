#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <fstream>

#include "BackwardDiff.h"

using namespace std;

BackwardDiff::BackwardDiff(float alphaIn, float lIn, int mIn, float kIn, float tfIn) {
    alpha = alphaIn;
    l = lIn;
    m = mIn;
    k = kIn;
    tf = tfIn;
};

void BackwardDiff::setf(float (*fIn)(float)){
    f = fIn;
};

vector<vector<float>> BackwardDiff::getSolution(){
    float h = l / m;

    float lambda = alpha*alpha*k / (h*h);

    float numberTimesteps = static_cast<int> (tf / k) + 1;

    vector<float> L(m-1);
    vector<float> u(m-1);
    vector<float> z(m-1);

    vector<vector<float>> w(numberTimesteps, vector<float>(m-1));

    // Inicializar vectores L y u para método Crout
    L[0] = 1 + 2*lambda;
    u[0] = -lambda / L[0];
    for (size_t i = 1; i < m-2; i++) {
        L[i] = 1 + 2*lambda + lambda*u[i-1];
        u[i] = -lambda / L[i];
    }
    L[m-2] = 1 + 2*lambda + lambda*u[m-3];

    // Inicializar primera fila w0
    for (size_t i = 0; i < m - 1; i++) {
        w[0][i] = f(l*(i+1) / m);
    }

    // Calcular w_j's
    for (size_t j = 1; j < numberTimesteps; j++) {
        z[0] = w[j-1][0] / L[0];
        for (size_t i = 1; i < m - 1; i++) {
            z[i] = (w[j-1][i] + lambda*z[i-1]) / L[i];
        }

        w[j][m-2] = z[m-2];

        for (int i = m-3; i >= 0; i--) {
            // cout << "Llega " << i << endl;
            w[j][i] = z[i] - u[i]*w[j][i+1];
        }
    }

    saveFile(w);

    return w;

};

void BackwardDiff::saveFile(vector<vector<float>> w){
    ofstream datos("backward-data.txt");

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