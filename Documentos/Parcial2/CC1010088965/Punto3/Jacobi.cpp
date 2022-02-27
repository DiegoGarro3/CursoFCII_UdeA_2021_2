#include "Jacobi.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

Jacobi::Jacobi(vector<vector<float>> coeffsIn, float errorIn) {
    coeffs = coeffsIn;
    degree = coeffsIn.size();
    error = errorIn;
}

Jacobi::~Jacobi() {
    vector<vector<float>>().swap(coeffs);
}

void Jacobi::setCoeffs(vector<vector<float>> coeffsIn) { coeffs = coeffsIn; }
vector<vector<float>> Jacobi::getCoeffs() const { return coeffs; };

void Jacobi::setDegree(float degreeIn) { degree = degreeIn; };
float Jacobi::getDegree() const { return degree; };

void Jacobi::setError(float errorIn) { error = errorIn; };
float Jacobi::getError() const { return error; };

void Jacobi::solve() {
    cout << "Inicia Jacobi:" << endl;
    vector<float> errors(degree);
    vector<float> currentGuess(degree, 0);
    vector<float> results(degree, 0);
    bool errorsTooLarge = true;

    do {
        for (size_t i = 0; i < degree; i++) {
            results[i] = coeffs[i][degree];
            for (size_t j = 0; j < degree; j++) {
                if (i != j) {
                    results[i] -= coeffs[i][j]*currentGuess[j];
                }
            }
            results[i] /= coeffs[i][i];
            cout << "x" << i << " = " << results[i] << ", ";
        }
        errorsTooLarge = false;
        for (size_t i = 0; i < degree; i++) {
            errors[i] = fabs(results[i] - currentGuess[i]);
            if (errors[i] > error) {
                errorsTooLarge = true;
            };
            currentGuess[i] = results[i];
        }
        cout << endl;
    } while (errorsTooLarge);
    cout << "El resultado de Jacobi fue la última línea." << endl;
}