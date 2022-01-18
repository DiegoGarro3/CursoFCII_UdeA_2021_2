#include <iostream>
#include <cmath>

#include "Exponential.h"

using namespace std;

Exponential::Exponential(float inX, int inN) {
    x = inX;
    N = inN;
}

int Exponential::factorial(unsigned int var) {
    if (var > 1) {
        return var * factorial(var - 1);
    } else {
        return 1;
    }
}

void Exponential::calculateExponential() {
    result = 0;
    for (int n = 0; n < N; n++)
    {
        result += (pow(x, n) / factorial(n));
    }
}

void Exponential::showResult() {
    cout << "La exponencial de " << x << " calculada con " << N << " terminos de precision es " << result << " mientras que la verdadera es " << exp(x) << endl;
}

