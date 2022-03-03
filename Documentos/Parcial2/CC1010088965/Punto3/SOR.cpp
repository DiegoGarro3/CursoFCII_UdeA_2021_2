#include "SOR.h"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

SOR::SOR(vector<vector<float>> coeffsIn, float errorIn, float relaxIn) {
    coeffs = coeffsIn;
    degree = coeffsIn.size();
    error = errorIn;
    relax = relaxIn;
}

SOR::~SOR() {
    vector<vector<float>>().swap(coeffs);
}

void SOR::setCoeffs(vector<vector<float>> coeffsIn) { coeffs = coeffsIn; }
vector<vector<float>> SOR::getCoeffs() const { return coeffs; };

void SOR::setDegree(float degreeIn) { degree = degreeIn; };
float SOR::getDegree() const { return degree; };

void SOR::setError(float errorIn) { error = errorIn; };
float SOR::getError() const { return error; };

void SOR::setRelax(float relaxIn) { relax = relaxIn; };
float SOR::getRelax() const { return relax; };

void SOR::solve() {
    cout << "Inicia SOR:" << endl;
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
            results[i] *= (relax / coeffs[i][i]);
            results[i] += (1 - relax) * currentGuess[i];
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
    cout << "El resultado de SOR fue la última línea." << endl;
}