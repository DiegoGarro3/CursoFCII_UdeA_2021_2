#ifndef JACOBI_H
#define JACOBI_H
#include <vector>

using namespace std;

#include "Jacobi.h"

class Jacobi {
    public:
        Jacobi(vector<vector<float>>, float);
        ~Jacobi();

        void setCoeffs(vector<vector<float>>);
        vector<vector<float>> getCoeffs() const;

        void setDegree(float);
        float getDegree() const;

        void setError(float);
        float getError() const;

        void solve();

    private:
        vector<vector<float>> coeffs;
        float degree;
        float error;
};

#endif